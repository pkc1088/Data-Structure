#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node 
{
    int value;
    struct node *next;
};

int insert_into_ordered_list( struct node **head, int value )
{
    struct node *new_node = (struct node *)malloc( sizeof( *new_node ) );
    int success = new_node != NULL;

    if ( success )
    {
        new_node->value = value;

        while ( *head != NULL && !( new_node->value < ( *head )->value ) ) 
        {
            head = &( *head )->next;
        }

        new_node->next = *head;
        *head = new_node;
    }

    return success;
}

FILE * display( const struct node *head, FILE *fp )
{
    for ( ; head != NULL; head = head->next )
    {
        fprintf( fp, "%d -> ", head->value );
    }

    fputs( "null", fp );

    return fp;
}

int main(void) 
{
    struct node *head = NULL;

    const size_t N = 10;

    srand( ( unsigned int )time( NULL ) );

    for ( size_t i = 0; i != N; i++ )
    {
        insert_into_ordered_list( &head, rand() % N );
    }

    fputc( '\n', display( head, stdout ) );

    return 0;
}
