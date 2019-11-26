# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 13:22:27 by gozsertt          #+#    #+#              #
#    Updated: 2019/11/26 16:32:02 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

i=1
nbtext=1
	echo ====================== MAIN PART ! ===================================
	echo ================== READ IN 3 TXT FILE ================================
while ((i <= 100))
do
	echo "TRY WITH BUFFER_SIZE = $i"
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c main.c
	for doc in 'text1.txt' 'text2.txt' 'text3.txt'
	do
	touch main_part_test.txt
	./a.out $doc > main_part_test.txt
	cat main_part_test.txt 
	printf "\n"
	echo ===================== DIFF TEXT $nbtext ==============================
	DIFF=$(diff $doc main_part_test.txt)
	if [ "$DIFF" == "" ] 
	then
    	printf "BUFFER_SIZE = $i ... Good, there are no diff baby ! ;)\n"
	fi
	if [ "$DIFF" != "" ] 
	then
    	printf "BUFFER_SIZE = $i ... Not Good, there are diff baby... :'(\n"
	fi
	sleep 2
	rm -Rf main_part_test.txt
	((nbtext+=1))
	done
	echo ======================================================================
	((i+=30))
	nbtext=1
done
i=1
nbtext=1
clear
	echo ===================== BONUS PART ! ===================================
	echo ================ MULTI FD - MIX 3 TXT FILE ===========================
while ((i <= 100))
do
	echo "TRY WITH BUFFER_SIZE = $i"
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$i get_next_line_bonus.c get_next_line_utils_bonus.c main.c
	touch bonus_part_test.txt
  	./a.out "text1.txt" "text2.txt" "text3.txt" > bonus_part_test.txt
	printf "\n"
	cat bonus_part_test.txt 
	printf "\n"
	echo "If the 'ZZZ' line is the first"
	echo "If the 'XXX' line is the second"
	echo "If the 'YYY' line is the last..."
	sleep 1
	echo "Its OKAY !"
	sleep 2
	rm -Rf bonus_part_test.txt
	echo ======================================================================
	((i+=30))
done