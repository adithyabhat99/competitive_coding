/*The structure of the class is
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap=100);
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/
MinHeap::MinHeap(int cap=100) 
{
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap];
    
}
void MinHeap::MinHeapify(int i){
    if(i>=heap_size) return;
    int l=2*i+1;
    int small=i;
    int r=2*i+2;
    if(l<heap_size && harr[l]<harr[small])
    small=l;
    if(r<heap_size && harr[r]<harr[small])
    small=r;
    if(small!=i){
        swap(harr[i],harr[small]);
        MinHeapify(small);
    }
}
int MinHeap ::  extractMin()
{
    if(heap_size<=0) return -1;
    if(heap_size==1) {
        heap_size--;
        return harr[0];
    }
    int ret=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return ret;
}
void MinHeap :: deleteKey(int i)
{
    if(i>=heap_size) return;
    harr[i]=-1;
    while(i>0 && harr[i]<harr[(i-1)/2])
    {
        swap(harr[i],harr[(i-1)/2]);
        i=(i-1)/2;
    }
    extractMin();
}
void MinHeap ::insertKey(int k)
{
   if(heap_size==capacity) return;
   heap_size++;
   int i=heap_size-1;
   harr[i]=k;
   while(i>0 && harr[i]<harr[(i-1)/2]){
       swap(harr[i],harr[(i-1)/2]);
       i=(i-1)/2;
   }
   MinHeapify(0);
}