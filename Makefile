# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 19:26:03 by ddosso-d          #+#    #+#              #
#    Updated: 2017/03/25 19:26:04 by ddosso-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror

C_FILE	=	end initialize main read_cases read_param read_instr \
			verif_instr cases_p cases_r cases_rr cases_s
C_DIR	=	checker_dir/
C_EXE	=	checker
C_OBJ	=	$(addprefix $(C_DIR), $(addsuffix .o, $(C_FILE)))

P_FILE	=	main read_cases read_param left_side right_side find_soluce \
 			print_soluce usefull useless_case reverse_or_not fusion_ins \
 			cases_p cases_r cases_rr cases_s
P_DIR	=	push_swap_dir/
P_EXE	=	push_swap
P_OBJ	=	$(addprefix $(P_DIR), $(addsuffix .o, $(P_FILE)))

all: $(C_EXE) $(P_EXE)

$(C_EXE): $(C_OBJ)
	@gcc $(FLAGS) $^ -o $@

$(P_EXE): $(P_OBJ)
	@gcc $(FLAGS) $^ -o $@

%.o: $(C_DIR) $(P_DIR)%.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -f $(C_OBJ) $(P_OBJ)

fclean: clean
	@rm -f $(C_EXE) $(P_EXE)

re: fclean all
