# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 00:02:40 by ayusa             #+#    #+#              #
#    Updated: 2026/05/02 14:22:25 by ayusa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

DEPFLAGS = -MMD -MP

AR      = ar rcs
RM      = rm -f

OBJDIR  = obj

C_INFO  = \033[1;36m
C_OK    = \033[1;32m
C_WARN  = \033[1;33m
C_RESET = \033[0m
TAG     = [libft]

MANDAT_SRCS = \
	ft_atoi.c ft_atol.c ft_atod.c ft_itoa.c ft_uitoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putstrn_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strcmp_ci.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
	ft_striteri.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
	ft_strchr.c ft_strrchr.c ft_strdup.c \
	ft_bzero.c ft_calloc.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_split_c.c ft_split.c free_split.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c get_next_line.c

BONUS_SRCS  = \
	ft_lstnew.c ft_lstadd_back.c ft_lstsize.c ft_lstadd_front.c \
	ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c

MANDAT_OBJS = $(addprefix $(OBJDIR)/, $(MANDAT_SRCS:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJDIR)/, $(BONUS_SRCS:.c=.o))

OBJS = $(MANDAT_OBJS)

ifdef WITH_BONUS
OBJS += $(BONUS_OBJS)
endif

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(C_INFO)==> $(TAG) archiving $(NAME)...$(C_RESET)\n"
	$(AR) $(NAME) $(OBJS)
	@printf "$(C_OK)==> $(TAG) build complete: $(NAME)$(C_RESET)\n"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

bonus:
	@make WITH_BONUS=1

clean:
	@printf "$(C_WARN)==> $(TAG) cleaning objects...$(C_RESET)\n"
	$(RM) -r $(OBJDIR)
	@printf "$(C_OK)==> $(TAG) clean complete$(C_RESET)\n"

fclean: clean
	@printf "$(C_WARN)==> $(TAG) fclean...$(C_RESET)\n"
	$(RM) $(NAME)
	@printf "$(C_OK)==> $(TAG) fclean complete$(C_RESET)\n"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus
