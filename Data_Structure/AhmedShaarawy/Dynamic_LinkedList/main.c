#include "linkedList.h"

int main(void)
{
    struct Node *list= NULL ;
    int data, newData ;
    char ch, check;
    Status state;
    while(1)
    {
        printf("Enter choice:\n");
        printf("    a/A to add node.\n");
        printf("    d/D to delete node.\n");
        printf("    l/L to delete all nodes.\n");
        printf("    c/C to change node data.\n");
        printf("    v/V to view all nodes data.\n");
        printf("    t/T to terminate program.\n");
        printf("Your choice: ");
        scanf("%s", &ch);
        switch(ch)
        {
            case 'a': case 'A':
            printf("Enter node data: ");
            scanf("%d", &data);
            check= addNode(&list, data);
            if(!check)
                printf("There is no size.\n");
            else
                printf("Node has been added.\n");
            break;
            /**************************************/
            case 'd': case 'D':
            printf("Enter node data: ");
            scanf("%d", &data);
            state= deleteNode(&list,data);
            if( state== LIST_EMPTY)
                printf("List is empty.\n");
            else if( state== NODE_NOT_FOUND)
                printf("Node not found.\n");
            else
                printf("Node has been deleted.\n");
            break;
            /***************************************/
            case 'c': case 'C':
            printf("Enter old node data: ");
            scanf("%d", &data);
            printf("Enter new node data: ");
            scanf("%d", &newData);
            state= changeNodeData(list,data,newData);
            if( state== LIST_EMPTY)
                printf("List is empty.\n");
            else if( state== NODE_NOT_FOUND)
                printf("Node not found.\n");
            else
                printf("Node has been changed.\n");
            break;
            /****************************************/
            case 'l': case 'L':
            check= deleteAll(&list);
            if(!check)
                printf("List is empty.\n");
            else
                printf("list has been deleted.\n");
            break;
            /****************************************/
            case 'v': case 'V':
            check= viewAll(list);
            if(!check)
                printf("List is empty.\n");
            break;
            /*****************************************/
            default:
            printf("False choice.\n");
            break;
        }
        if( ch== 't' || ch== 'T')
            break;
    }
    return 0;
}
