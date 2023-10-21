class list{
  int [] arr;
  int s, len;
  list(){
    s = 0;
    len = 1;
    arr = new int[len];
  }

  void push(int x) {
    if(s==len) resize();
    arr[s] = x;
    s++;
  }

  int pop() {
    int temp = arr[s-1];
    s--;
    if(len/3>=s) resize();
    return temp;
  }

  void print() {
    System.out.print("[ ");
    for(int i=0; i<s; i++) System.out.print(arr[i]+ " ");
    System.out.println(']');
  }

  void resize() {
    len = s*2;
    int [] brr = new int[len];
    for(int i=0; i<s; i++) {
      brr[i] = arr[i];
    }
    arr = brr;
  }
}

public class stack{
  public static void main(String[] args) {
    list ob = new list();
    ob.push(5);
    ob.push(7);
    ob.push(9);

    ob.print();

    System.out.println(ob.pop());
    
    ob.print();
  }
}