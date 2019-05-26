#include <vector>

/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
      if(pq.empty())
        {
            return 0;
        }
        int index=pq.size()-1;
        int ans=pq[0];
        pq[0]=pq[index];
        pq.pop_back();
        int parentIndex=0;
        int childIndex1=(2*parentIndex)+1;
        int childIndex2=(2*parentIndex)+2;
        while(childIndex2<pq.size()-1)
        {
            int minindex=parentIndex;
            if(pq[minindex]>pq[childIndex1]||pq[minindex]>pq[childIndex2]){
            if(pq[minindex]>pq[childIndex1])
            {
                minindex=childIndex1;
            }
            if(pq[minindex]>pq[childIndex2])
            {
                minindex=childIndex2;
            }
            int temp=pq[minindex];
            pq[minindex]=pq[parentIndex];
            pq[parentIndex]=temp;
            parentIndex=minindex;
           childIndex1=(2*parentIndex)+1;
           childIndex2=(2*parentIndex)+2;}
           else
           {
               break;
           }
        }
      return ans;
    
        
    }
    
    
};


//EASY HAI  Heapify wala concept -->Upheapify And Downheapify
