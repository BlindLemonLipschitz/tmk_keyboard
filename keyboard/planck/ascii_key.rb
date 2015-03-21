#!/usr/bin/env ruby
require "erb"
require 'optparse'
# Usage: ruby ascii_key.rb FILE
@results = []
options = {}
optparse = OptionParser.new do|opts|
    opts.banner = "Usage: ruby ascii_key.rb [-s] FILE"
    options[:show] = false   
  opts.on( '-s', '--show', 'Show effective key, not TRNS' ) do
    options[:show] = true   
  end
  opts.on( '-h', '--help', 'Display this screen' ) do
    puts opts
    exit
  end
end
optparse.parse!
def get_array_of_keymap_arrays(file)
  text = File.read(file)
  grab = text.to_enum(:scan, /KEYMAP(\(.*?\)),\n/m).map { Regexp.last_match } 
  @function_text = text.to_enum(:scan, /\/\/ (FN\d+.*?)\n/m).to_a
  @layer_description = text.to_enum(:scan, /\/\/ (layer \d+.*?)\n/m).to_a
  grab.each do |keymap|
    @results << eval(keymap.to_s.gsub(/\/.*$/, '').gsub!(/\s/, '').gsub!(/.*KEYMAP/, '%w').gsub(/,/, ' ').gsub(/\/\*.*\*\//,'').gsub(/MS_/, 'M_'))
  end
end

get_array_of_keymap_arrays(ARGV[0])

@results.collect!.each_with_index do |keymap,layer|
  @layer = layer
  keymap.collect!.each_with_index do |key,index|
    if key == "TRNS" && options[:show]
      key = @results[@layer - 1][index].sub(/.\b/,'*')
    end
    key.center(6)
  end
end
output = ARGV[0].sub(/[^.]+\z/,"txt")
File.open(output, 'w+') do |file|
  @results.each_with_index do |keymap,layer|
    @k = keymap
    text = File.read("./ascii_template.erb")
    text = ERB.new text
    text = text.result
    file.puts @layer_description[layer]
    file.puts "*effective key from previous non-transparent layer's mapping" if options[:show]
    file.puts(text)
    file.puts("\n\n")
  end
  file.puts("FUNCTIONS:")
  times = (@function_text.length / 3)
  times += 1 unless @function_text.length%3 == 0
  @sliced_func = @function_text.each_slice(times).to_a
  @sliced_func[0].zip(@sliced_func[1],@sliced_func[2]).each do |n|
    n[2] ||= ' '
    file.puts "#{n[0][0].ljust(32) + n[1][0].ljust(32) + n[2][0].ljust(32)}"
  end
end
