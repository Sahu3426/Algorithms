#include <string>
#include <bits/stdc++.h>
// Rehashing is the process of increasing the bucket size by 2 so that the load factor get decreases.
// Load Factor defined as the size of bucket array divided by size of map( here count)
using namespace std;

template <typename V>
class MapNode {
	public:                //Node of map which contains key (string assumed) and value
		string key;
		V value;
		MapNode* next;           //Since it is a separate chaining so we are using linked list for storing things in bucket array


		MapNode(string key, V value) { //Parametrized constructor for initializing  the map's nodes
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {          //Recursively deleting the nodes.
			delete next;
		}
};

template <typename V>   // For every class we have to define the template the separately
class ourmap {
	MapNode<V>** buckets;     //Pointer which is pointing to array of bucketArrays
	int count;               //Count variable is used for the counting the size of map
	int numBuckets;          //Size of bucket array

	public:
	ourmap() {               //Initially we are taking count as 0 and no. of bucket array as 5.
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
		for (int i = 0; i < numBuckets; i++) {      //Initializing all the bucket array to zero as they might point  to any garbage value
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {      //Deallocating the numBucket array.
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {       //Function for returning the size of bucket array
		return count;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex( key);   //For getting index through getBucketIndex function
		MapNode<V>* head = buckets[bucketIndex];      //initializing head with  that index
		while (head != NULL) {           //traversing through the linked list of that bucketArray
			if (head->key == key) {
				return head->value;    //Returning value if found
			}
			head = head->next;
		}
		return 0;    //If not found return 0
	}

	private:
	int getBucketIndex(string key) {
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {   //"abd"= 'a'*37*37 +'b'*37 +'c' *1
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;          //So value does not overflow     // HASHING FUNCTION FOR HASHCODE
			currentCoeff *= 37;                         //37 is a prime number
			currentCoeff = currentCoeff % numBuckets;   //So value do es not overflow
		}

		return hashCode % numBuckets;         // COMPRESSION FUNCTION AFTER THE HASHING CODE GENERATION SO THAT MAY BE COME UNDER SIZE OF BUCKERARRAY
	}
     void rehash()   //REHASHING
     {

         MapNode<V> **temp=buckets;
         buckets= new MapNode<V>*[2*numBuckets]; //Increasing the bucket size by 2
        for(int i=0;i<2*numBuckets;i++)
        {
            buckets[i]=NULL;  //Initialzing the arrat by NULL;
        }
        int oldBucketCount=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0;i<oldBucketCount;i++)
        {
            MapNode<V> *head=temp[i];
            while(head!=NULL)
            {
                string key=head->key;  //INserting again in newly made  Bucket array
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketCount;i++)
        {
            MapNode<V>* head=temp[i];
            delete head;
        }
        delete []temp;
     }
	public:
	void insert(string key, V value) {    // INSERTING the key nad pair
		int bucketIndex = getBucketIndex( key);          //finding the proper index for inserting key in bucketArray
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {   //Traversing if key is already  there or nor
			if (head->key == key) {
				head->value = value;  // If key is there update it
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key, value); //If key is not there then make a node to insert it in linked list of that index of bucketarray
		node->next = head;
		buckets[bucketIndex] = node;
		count++; //Since new node is formed so increase size by 1
	    double loadFactor=(1.0*count)/numBuckets;
	    // cout<<"loadFactor:"<<loadFactor<<endl;  
	    if(loadFactor>0.7)
        {
            cout<<"loadFactor:"<<loadFactor<<endl;  //Called when load factor grt increases by 0.7
            rehash();
        }
	}


	V remove(string key) {
		int bucketIndex = getBucketIndex( key);  // Find index for that key
		MapNode<V>* head = buckets[bucketIndex];  // point to current node.
		MapNode<V>* prev = NULL;  //taking prev which will  pint to previous  passed node
		while (head != NULL) {
			if (head->key == key) {
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;  // if no node is there  then
				} else {
					prev->next = head->next;    //Deleting node is very much similar to lonked list.
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}

};

int main()
{

    ourmap<int> mp;
    mp.insert("abc",1);
     mp.insert("abc1",2);
      mp.insert("abc2",13);
       mp.insert("abc3",14);
       mp.insert("abc4",15);
       mp.insert("abc5",16);
       mp.insert("abc6",17);
       mp.insert("abc7",18);
       mp.insert("abc8",19);
       mp.insert("abc9",21);
      cout<<mp.getValue("abc")<<endl;
}
