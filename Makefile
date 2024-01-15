TARGET = my_ngram
SRC = main.c
CFLAGS = 

$(TARGET) : $(SRC)
  gcc $(CFLAGS) $@ $<

.PHONY : fclean

fclean :
  @rm -r $(TARGET)