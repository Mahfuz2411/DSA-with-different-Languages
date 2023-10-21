using System;

class list{
  int [] arr;
  int s, len;
  
  void resize() {
    len = s*2;
    int [] brr = new int[len];
    for(int i=0; i<s; i++) {
      brr[i] = arr[i];
    }
    arr = brr;
  }
  
  public list(){
    s = 0;
    len = 1;
    arr = new int[len];
  }

  public void push(int x) {
    if(s==len) resize();
    arr[s] = x;
    s++;
  }

  public int pop() {
    int temp = arr[s-1];
    s--;
    if(len/3>=s) resize();
    return temp;
  }

  public void print() {
    Console.Write("[ ");
    for(int i=0; i<s; i++) Console.Write(arr[i]+ " ");
    Console.WriteLine(']');
  }
}

public class HelloWorld {
    public static void Main(string[] args) {
        list ob = new list();
        ob.push(5);
        ob.push(7);
        ob.push(9);
    
        ob.print();
    
        Console.WriteLine(ob.pop());
        
        ob.print();
    }
}