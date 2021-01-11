
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS 26
 typedef enum
  { FALSE = 0, TRUE = 1 } boolean;
  typedef struct node
  {
    char letter;
    int is_end_of_word;
    int count;
    struct node *children[NUM_LETTERS];
  } node;

 
node *getNode(void) 
{ 
    node *pNode = NULL; 
  
    pNode = (node *)malloc(sizeof(node)); 
  
    if (pNode) 
    { 
        int i=0; 
  
        pNode->is_end_of_word =FALSE; 
        pNode->count=0;
        pNode->letter='\0';
  
        for (i = 0; i < NUM_LETTERS; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 


node* insert(node *head, char key) 
{ 
  
        if(!head->children[key-'a']) 
            head->children[key-'a'] = getNode(); 
  
        head = head->children[key-'a'];
        return head;
    } 
  
void preorder( node *follow, char* hold, int s){
  int i = 0;
  if(follow == NULL){
    return;
  }
 
  if (follow->is_end_of_word) {
    hold[s] = 0;
    if(hold[0]!='\0')
    printf("%s %d\n", hold,follow->count);
  }

  for(i = 0; i < 26; i++){
    hold[s] = 'a'+i;
    preorder(follow->children[i], hold, s + 1);
  }
}
  
  void postorder( node *follow, char* hold, int s){
  int i = 0;
  if(follow == NULL){
    return;
  }
  if (follow->is_end_of_word) {
    hold[s] = 0;
   if(hold[0]!='\0')
    printf("%s %d\n", hold,follow->count);
  }
  
  for(i = NUM_LETTERS-1; i >= 0; i--)
  {
    hold[s] = 'a'+i;
    postorder(follow->children[i], hold, s+1);
  }
}
void free_tree(node* root){
   int i = 0;
  if(root==NULL){
    return;
  }
  for(i = 0; i < 26; i++){
    free_tree(root->children[i]);
  }
  if(root->letter!='$')
      free(root);
  return;
}


int main (int argc , char* argv[])
{ 
int bool=0;
  if(argc>1){
  if(*argv[1]=='r')
   bool=1;
  else
  return -1;}
  char c = 't';
  node root;
  root.letter = '$';
  root.is_end_of_word=FALSE;
  root.count=0;
  for (int i = 0; i < NUM_LETTERS; i++)
    {
      root.children[i] = NULL;
    }
    int longest_word=0;
    int temp=0;
while(1){
    node* ptr=NULL;
    ptr=&root;
    temp=0;
  while (1)
    {
      c=getchar();
      if(c == ' '||c=='\n' ||c==EOF)
      break;
      c = tolower (c);
      if (c - 'a' > 26 || c - 'a' <0)
	continue;
      ptr=insert (ptr,c);
      temp++;
    }
    if(temp>longest_word)
    longest_word=temp;
    ptr->is_end_of_word=TRUE;
    ptr->count++;
    if(c==EOF)
    break;
}
int s=0;
char holds[longest_word+1];
if(bool)
postorder(&root,holds,s);
else
preorder(&root,holds,s);


free_tree(&root);



  return 0;
}
