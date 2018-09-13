#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char *author;
    char *subject;
    int book_id;
} *book;

int main()
{
    void print_bookinfo( struct Books book );
    void print_book(struct Books *book);
    
    struct Books CProgramming;
    
    strcpy( CProgramming.title, "C Programming");
    CProgramming.author = "宁金";
    CProgramming.subject = "如何快速掌握一门语言";
    CProgramming.book_id = 1;
    CProgramming.author = "废物"; 
    print_bookinfo(CProgramming);
    
    struct Books Hello = {"Hello", "Dan Rach", "Hello yourself", 12};
    print_bookinfo(Hello);
    book = &Hello;
    
    print_book(book);

    return 0;
}

void print_bookinfo( struct Books book )
{
    printf("title: %s\n", book.title);
    printf("author: %s\n", book.author);
    printf("subject: %s\n", book.subject);
    printf("book_id: %d\n", book.book_id);
}

void print_book( struct Books *book )
{
    printf("title: %s\n", book->title);
    printf("author: %s\n", book->author);
    printf("subject: %s\n", book->subject);
    printf("book_id: %d\n", book->book_id);
}
