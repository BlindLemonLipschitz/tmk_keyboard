#!/bin/env ruby
require 'optparse'
# convert a string into macro syntax for TMK firmware
# usage:  ruby macro.rb STRING NAME_OF_MACRO
# Example: 
# prompt# ruby macro.rb "this\"is aPa33word" name
# "T(T), T(H), T(I), T(S), D(LSFT), T(QUOT), U(LSFT), T(I), T(S), D(LSFT),/
# T(SPC), U(LSFT), T(A), D(LSFT), T(P), U(LSFT), T(A), T(3), T(3), T(W),/
# T(O), T(R), T(D), "
#
options  = {}
optparse = OptionParser.new do |opts|
  @opts = opts
  opts.banner  = "Convert a string into macro syntax for TMK firmware\n  Usage:  ruby macro.rb STRING NAME_OF_MACRO"
  options[:password] = false
  opts.on('-p', '--password PASSWORD', 'Your password') do |pw|
    options[:password] = pw
  end
  options[:name]  = 'NAME'
  opts.on('-n', '--name NAME', 'Name for your macro') do |name|
    options[:name] = name.upcase
  end
    options[:clipboard] = false   
  opts.on( '-c', '--clipboard', 'Copy macro to OS X clipboard, only on OS X' ) do
    options[:clipboard] = true   
  end
  opts.on( '-h', '--help', 'Display this screen' ) do
    puts opts
    exit
  end
end
begin      
  optparse.parse(ARGV)
rescue OptionParser::InvalidOption => e
  puts e
  puts @opts
  exit(1)
end
optparse.parse!
name = options[:name]
password = options[:password]
unless password
  puts @opts
  raise ArgumentError.new('Password option is required!')
  exit(1)
end

shifted_special_chars = { "+" => "EQL", "_" => "MINS", "!" => "1", "@" => "2", "#" => "3", '$' => "4", "%" => "5", "^" => "6", "&" => "7", "*" => "8", "(" => "9", ")" => "0" , "~" => "GRV", "?" => "SLSH", "<" => "COMM", ">" => "DOT", "{" => "LBRC", "}" => "RBRC", "|" => "BSLS", '"' => "QUOT", ":" => "SCLN"}

unshifted_special_chars = { "=" => "EQL", "-" => "MINS", "`" => "GRV", "/" => "SLSH", "," => "COMM", ";" => "SCLN", "." => "DOT", "[" => "LBRC", "]" => "RBRC", "\\" => "BSLS", '"' => "QUOT", " " => "SPC"}

def type(char)
  "T(#{char})"
end

def shift(char)
  "D(LSFT), #{char}, U(LSFT)"
end
@mac = ""
password.each_char do |char|
  case 
  when char =~ /[A-Z]/
    @mac << shift("#{type(char)}")
  when char =~ /[a-z]/
    @mac << type(char).upcase
  when char =~ /[\d]/
    @mac << type(char)
  when shifted_special_chars.has_key?(char)
    char = shifted_special_chars[char]
    @mac << shift("#{type(char)}")
  when unshifted_special_chars.has_key?(char)
    char = unshifted_special_chars[char]
    @mac << type(char)
  end
  @mac << ", "
end
space = ' ' * (14 - name.length)
macro = "#define MACRO_#{name}" + space + "MACRO(I(15), #{@mac}END)" 

if options[:clipboard]
  IO.popen('pbcopy', 'w') { |f| f << macro }
else
  puts macro
end
