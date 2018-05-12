#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}

deque<int> dq;
deque<int>::iterator dit;
map<int,int> m;
map<int,int>::iterator mit;
int Size;
LRUCache::LRUCache(int N)
{
    Size = N;
    m.clear();
    dq.clear();
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    dit = find(dq.begin(),dq.end(),x);
    if(dit==dq.end()) {
        if(dq.size()>=Size) {
            int temp = *(dq.end()-1);
           // cout<<"\n Size full deleting "<<temp<<endl;
            dq.pop_back();
            m.erase(temp);
        }
        dq.push_front(x);
        m.insert(make_pair(x,y));
    } else {
        m.erase(x);
        m.insert(make_pair(x,y));

        dq.erase(dit);
        dq.push_front(x);
    }

}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    mit = m.find(x);
    if(mit==m.end()) return -1;
    else {
        set(x,mit->second);
        return mit->second;
    }
}