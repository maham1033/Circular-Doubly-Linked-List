#include <iostream>
using namespace std;

class Node {
	public:
    int data;
    Node* next;
    Node* prev;
};

class C_LinkedList {
	 Node* head;
	 Node* tail;   
  public:
  	
    C_LinkedList(){
      head = NULL;
    }
    
    
    
    //display the data
    void Display() {
      Node* temp = head;
      if(temp != NULL) {
        while(true) {
          cout<<temp->data<<" -> ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"NULL";
      }
    }
    
    
 
    //Add node at the start
    void insert_H(int d) {
      Node* t = new Node();
      t->data = d;
      t->next = NULL;
      t->prev = NULL; 
      if(head == NULL) {
      	tail = t;
        head = t;
        t->next = head;
        t->prev = head;
      } else {
        Node* nptr = head;
        while(nptr->next != head)
          nptr = nptr->next;
        nptr->next = t;
        t->prev = nptr;
        t->next = head;
        head->prev = t;
        head = t;
        tail = nptr;
      }    
//      cout<<"INSERTED";
    }
    
    

	
	
	//deletion at head
	void delete_H() {
		if(head==NULL){
			cout<<"NULL";
		}
		else{
		  if(head->next == head) {
          head = NULL;
          tail = NULL;
		  } 
		  else{
          Node* t = head;
          Node* D = head;
          while(t->next != head) {
            t = t->next;
          }
         
          head = head->next;
          head->prev = t;
          t->next = head;
		   tail = t; 
          delete(D); 
		  }
		}
    }  
    
    // insertion at tail
    void inser_T(int d) {
      Node* t = new Node();
      t->data = d;
      t->next = NULL;
      t->prev = NULL; 
      if(head == NULL) {
        head = t;
        tail = t;
        t->next = head;
        t->prev = head;
      } 
	  else {
        Node* temp = head;
        while(temp->next != head){
          temp = temp->next;
		  }
        temp->next = t;
        t->next = head;
        t->prev = temp;
        head->prev = t;
        tail = temp;
      }    
    }
    
    
    
    //deletion at tail
    void delete_T() {
      if(head != NULL) {
        if(head->next == head) {
          head = NULL;
          tail = NULL;
        } 
		else {
          Node* temp = head;
          while(temp->next->next != head){
            temp = temp->next;}
          Node* t = temp->next;
          temp->next = head;
          head->prev = temp;
          tail = temp;
          delete(t); 
        }
      }
    }
    
    
        
        //Insert node at the specific position 
    void insert_SP(int d, int position) {
      Node* t = new Node(); 
      t->data = d;
      t->next = NULL;
      Node* temp = head;
      int size = 0;
      if(temp != NULL) {
        size++;
        temp = temp->next;
      }
      while(temp != head) {
        size++;
        temp = temp->next;
      }
      if(position < 1 || position > (size+1)) {
        cout<<"\nInavalid position.";
      } else if (position == 1) {
      
        if(head == NULL) {
          head = t;
          tail = t;
          head->next = head;
          head->prev = head;
        } else {
          while(temp->next != head) {
            temp = temp->next;
          }
          temp->next = t;
          t->prev = temp;
          t->next = head;
          head->prev = t;
          head = t;
          tail = temp;
        }
      } else {

        temp = head;
        for(int i = 1; i < position-1; i++)
          temp = temp->next;
        t->next = temp->next;
        t->next->prev = t;
        t->prev = temp;
        temp->next = t;  
      }
    }
    
    
	
	 // deletion at specifc position
	 void delete_SP(int position) {
      Node* D = head; 
      Node* t = head;
      int size = 0;

      if(t != NULL) {
        size++;
        t = t->next;
      }
      while(t != head) {
        size++;
        t = t->next;
      }

      if(position < 1 || position > size) {
        cout<<"\nInavalid position.";
      } else if (position == 1) {
        if(head->next == head) {
          head = NULL;
        } else {     
          while(t->next != head)
            t = t->next;
          head = head->next;
          t->next = head; 
          head->prev = t;
          tail=t;
          delete(D); 
        }
      } else {
        t = head;
        
        for(int i = 1; i < position-1; i++){
          t = t->next;}
        D = t->next;
        t->next = t->next->next;
        t->next->prev = t;
        delete(D); 
      }
    }
	  
    
    // searching node with specific data
    void Search(int d) {
      Node* t = head;
      int found = 0;
      int index = 0;

      if(t != NULL) {
        while(1) {
          index++;
          if(t->data == d) {
            found++;
            break;
          }
          t = t->next;
          if(t == head) 
		  {
		  break;
		  }     
        }
        
        
        if (found == 1) {
          cout<<d<<" is found at index = "<<index<<".\n";
        } 
		else {
          cout<<d<<" is not found in the list.\n";
        }
      } 
	  else {
        cout<<"The list is empty.\n";
      }
    } 
   
};

// test the code 
int main() {
  C_LinkedList LL;
  cout<<"After nsertion at head "<<endl;
  LL.insert_H(2);
  LL.insert_H(3);
  LL.insert_H(4);
  LL.insert_H(5);
  LL.insert_H(6);
  LL.Display();  
  cout<<"After deletion at head "<<endl;
  LL.delete_H();
  LL.Display();
  cout<<"After nsertion at tail "<<endl;
  LL.inser_T(1);
  LL.inser_T(0);
  LL.Display();
  cout<<"After deletion at tail "<<endl;
  LL.delete_T();
  LL.Display();
  cout<<"After insertion at specific position"<<endl;
  LL.insert_SP(9,2);
  LL.Display();
  cout<<"After deletion at specific position"<<endl;
  LL.delete_SP(2);
  LL.Display();
  cout<<"searching specific node"<<endl;
  LL.Display();
  LL.Search(5);
   cout<<"After insertion at specific position"<<endl;
  LL.insert_SP(8,5);
  LL.Display();
  
  return 0; 
}
