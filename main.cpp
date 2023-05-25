#include <iostream>
#include <stdio.h>
#include <stdlib.h>

# define SIZE 100
# define EMPTY_DATA -1
# define SIDE_LEFT 0
# define SIDE_RIGHT 1

struct tree_node {
    char data;
    int left;
    int right;
    int parent;
};

struct tree_node tree[SIZE];
int side, temp, index = 0, opt = EMPTY_DATA;
char parent, node;

void add_tree_node(int parent, char data, int side);
int  search_tree_by_data(char data);
void show_menu();
void clear_screen();

void user_input_add_node();
void user_input_search_node();

int main() {
    do {
        show_menu();
        scanf("%d", &opt);

        if (opt == 1) {
            user_input_add_node();
        } else if (opt == 2) {
            user_input_search_node();
            system("pause");
        }
    } while(opt != 0);

    return 0;
}

int search_tree_by_data(char data) {
    if (index == 0) {
        return 0;
    }

    for (int i = 0; i < index; i++) {
        if (tree[i].data == data) {
            return i;
        }
    }
}

void add_tree_node(int parent, char data, int side) {
    if (side == SIDE_LEFT) {
        tree[parent].left = index;
    } else if (side == SIDE_RIGHT) {
        tree[parent].right = index;
    }

    tree[index].data = data;
    tree[index].parent = parent;
    tree[index].left = EMPTY_DATA;
    tree[index].right = EMPTY_DATA;

    index++;
}

void show_menu() {
    clear_screen();

    for (int i = 0; i < index; i++) {
        printf("| %c", tree[i].data);
    }

    printf("\n1 - Insert node");
    printf("\n2 - Search node");
    printf("\n0 - Exit");
    printf("\n\nEnter a option: ");
}

void clear_screen() {
#if _WIN32
    system("cls");
# else
    system("clear");
# endif
}

void user_input_add_node() {
    printf("\nEnter parent value: ");
    scanf("%c", &parent);
    scanf("%c", &parent);

    printf("\nEnter node value: ");
    scanf("%c", &node);
    scanf("%c", &node);

    printf(
            "\nEnter subtree side (Left=%d / Right=%d): ",
            SIDE_LEFT,
            SIDE_RIGHT
    );
    scanf("%d", &side);

    temp = search_tree_by_data(parent);
    add_tree_node(temp, node, side);
}

void user_input_search_node() {
    printf("\nEnter value node: ");
    scanf("%c", &node);
    scanf("%c", &node);

    temp = search_tree_by_data(node);

    std::cout << "Node = ";
    std::cout << tree[temp].data << std::endl;
    std::cout << "Left child = ";
    std::cout << tree[tree[temp].left].data << std::endl;
    std::cout << "Right child = ";
    std::cout << tree[tree[temp].right].data << std::endl;
}
