#include<bits/stdc++.h>
using namespace std;
int main() {
    int l,q;
    cin >> l >> q;
    set<int> st;
    st.insert(0);
    st.insert(l);
    while(q--) {
        int a,b;
        cin >> a >> b;
        if(a==1) {
            st.insert(b);
        }
        else {
        auto it = st.upper_bound(b);
        cout << *it-*(prev(it)) << endl;
        }   
    }
}