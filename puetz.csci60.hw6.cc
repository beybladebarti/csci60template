#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
  string name;
  int id;
  float gpa;
};

/*class IntSet {
public:
  Set() { data.clear(); }
  void Insert(int val) {
    if (Find(val)) return;
    data.push_back(val);
  }
  bool Find(int val) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == val) {
        return true;
      }
    }
    return false;
  }
  int GetSize() { return data.size(); }
  void Print() {
    for (int i = 0; i < data.size(); i++) {
      cout << data[i];
    }
    cout << endl;
  }
private:
  vector<int> data;
};*/


ostream& operator<< (ostream& out, Student s){
  out<<"Name: "<<s.name<<endl;
  out<<"ID: "<<s.id<<endl;
  out<<"GPA: "<<s.gpa<<endl;
  return out;
}

bool operator< (const Student& a, const Student& b){
  return a.gpa<b.gpa;
}

bool operator== (const Student &a, const Student &b){
  if(a.id == b.id){
    return true;
  }
  else return false;
}

template<typename T>
class TemSet{
public:
  TemSet() { data.clear(); }
  void Insert(T val){
    if(Find(val)) return;
    data.push_back(val);
  }
  bool Find(T val){
    for(int i = 0; i<data.size(); i++) {
      if(data[i] == val){
        return true;
      }
    }
    return false;
  }
  int GetSize() { return data.size(); };
  void Print(){
    for (int i = 0; i<data.size(); i++){
      cout<<data[i]<<endl;
    }
  }
  void Sort(){
    T tempJ = T();
    T tempK = T();
    for(int j = 0; j<data.size(); j++){
      for(int k = j+1; k<data.size(); k++){
        if(data[j]<data[k]){
          tempJ = data[j];
          tempK = data[k];
          data[k] = tempJ;
          data[j] = tempK;
          }
        }
      }
    }
private:
  vector<T> data;
};

template<typename T>
class TemOrSet : public TemSet<T>{
public:
  TemOrSet(): TemSet<T>() {};
  void Insert(T val){
    TemSet<T>::Insert(val);
    TemSet<T>::Sort();
  }
};

int main() {

  TemSet<int> s1;
  s1.Insert(7);
  s1.Insert(5);
  s1.Insert(5);
  s1.Insert(1);
  s1.Insert(7);
  cout << "Set size is: " << s1.GetSize() << endl;
  if (s1.Find(7)) cout << "7 found" << endl;
  if (s1.Find(2)) cout << "2 found" << endl;
  cout<<endl;

  TemOrSet<Student> s2;

  Student t1 = { "Ann", 17, 4.0 };
  Student t2 = { "Bob", 5, 2.6 };
  Student t3 = { "Chris", 26, 3.7 };
  Student t4 = { "David", 9871, 3.9 };
  s2.Insert(t1);
  s2.Insert(t1);
  s2.Insert(t2);
  s2.Insert(t2);
  s2.Insert(t1);
  s2.Insert(t3);
  cout << "Set size is: " << s2.GetSize() << endl;
  s2.Print();
  if (s2.Find(t3)) cout << "t3 found" << endl;
  if (s2.Find(t4)) cout << "t4 found" << endl;

  return 0;
}
