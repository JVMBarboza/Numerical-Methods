#!/bin/bash

#############################################################################
#Script Name	: verifiesDependencies.sh                                                                                             
#Description	: verifies and installs dependencies to properly run codes                                                                                                                                                                         
#Author       	: João Victor M. Barboza                                                
#Email         	: victorbarboza7657@gmail.com                                           
#############################################################################


echo "Welcome! Would you like to automatically install dependencies not installed?:[type yes/no]"
read ans

name=gcc

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
	echo "gcc not installed"
	if [ $ans = "yes" ];
	then
		sudo apt-get install gcc
	else
		echo "it can be installed with: sudo apt-get install gcc"
	fi
else
	echo "gcc installed [x]"
fi



name=python3  

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
        echo "python not installed"
	if [ $ans = "yes" ];
	then
		sudo add-apt-repository ppa:ubuntu-toolchain-r/ppa
		sudo apt install python3.7
	else
		echo "it can be installed with: sudo apt install python3.7"
	fi
else
        echo "python installed [x]"
fi


name=pip  

dpkg -s $name &> /dev/null

if [ $? -ne 0 ];
then
        echo "pip not installed"
	if [ $ans = "yes" ];
	then
		sudo apt install python3-pip
		
		echo "installing python packages"
		pip3 install -r requirements.txt
	else
		echo "it can be installed with: sudo apt install python3-pip"
	fi
else
        echo "pip installed [x]"
	pip3 install -r requirements.txt

fi