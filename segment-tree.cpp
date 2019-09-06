#include <bits/stdc++.h>

using namespace std;

#define MOD 1e9+7
#define N 100005

int tree[N*4];
int arr[N];

void build(int ind, int l, int r){
  if(l==r){
    tree[ind] = arr[ind];
  } else {
    int mid = (l+r)/2;
    build(ind*2, l, mid);
    build(ind*2+1, mid+1, r);

    tree[ind] = tree[ind*2] + tree[ind*2+1];
  }
  return;
}

void update(int ind, int l, int r, int x, int val) {

  if(l > x || r < x) return;
  if(l == x && r==x) { 
    tree[ind] = val;
    return; 
  }

  int mid = (l+r)/2;
  update(ind*2, l, mid, x, val);
  update(ind*2+1, mid+1, r, x, val);

  tree[ind] = tree[ind*2] + tree[ind*2+1];
}

int query(int ind, int l, int r, int llook, int rlook) {

  if(l > rlook || r < llook) return;
  if(l == llook && r==rlook) { 
    return tree[ind]; 
  }
  int mid = (l+r)/2;
  return query(ind*2, l, mid, llook, rlook) + query(ind*2+1, mid+1, r, llook, rlook);
}



int main(){

}