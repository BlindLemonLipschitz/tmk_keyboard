#!/bin/bash

if [ -e ./keymap_passwords.h ]
then
	echo " keymap_passwords.h exists "
else
	if [ -e ./keymap_passwords.h.gpg ]
	then
		echo " decrypting...."
		gpg2 -o ./keymap_passwords.h -d ./keymap_passwords.h.gpg
	fi
fi
