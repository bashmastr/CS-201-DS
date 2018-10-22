#include <iostream>
using namespace std;


class circular_array_queue{

	private:
		int *arr,front,rear,size;

	public:

		circular_array_queue():front(-1),rear(-1){
			cout<<"Enter the size of the queue\n";
			cin>>size;
			arr = new int [size];
		}

		void n_queue(int var){
			if(rear == size-1 && front == 0 || rear == front -1){
				cout<<"queue full\n";
				return;
			}


			if(front == -1){
				cout<<"add first entry\n";
				rear = front = 0;
				arr[rear] = var;
				return;
			}
			if (rear == size -1 && front != 0){
				rear = 0;
				arr[rear] = var;
				return;
			}
			else{
				rear++;
				arr[rear] = var;
			}
		}

		void d_queue(){
			if(front == -1){
				cout<<"empty queue\n";
				return;
			}
			arr[front] = 0;
			if(front == rear){
				front = -1;
				rear = -1;
				return;
			}
			if(front == size-1)
				front = 0;
			else
				front++;
		}
		void queue_show(){
			for(int i = 0 ; i < size; i++){
				cout<<arr[i]<<" ";
			}
		}


};


int main(){
	circular_array_queue q;
	q.n_queue(5);
	q.n_queue(7);
	q.n_queue(1);
	q.n_queue(2);
	q.n_queue(3);
	q.d_queue();
	q.d_queue();
	q.d_queue();
	q.d_queue();
	q.d_queue();

	q.n_queue(6);

	q.queue_show();


	return 0;
}