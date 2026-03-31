#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Datatype {
  private:
    string name;     // To store the name of the datatype
    size_t sizeInBytes;   // To store the size of the datatype in Bytes
    size_t sizeInBits;    // To store the size of the datatype in Bits
    bool isSigned;        // To know if the datatype is signed or not
    long double maxValue; // To store the max. value that can be stored in the datatype
    long double minValue; // To store the min. value that can be stored in the datatype
    

  public:
    // Constructor
    Datatype( string n, size_t s, bool sign, long double minV, long double maxV ) : name(n), sizeInBytes(s), sizeInBits(s*8), isSigned(sign), minValue(minV), maxValue(maxV) {}
    
    // Display function
    void display() {
      cout<<"------------------------------"<<endl;
      cout<<"Datatype: "<<name<<endl;
      cout<<"Size(Bytes): "<<sizeInBytes<<endl;
      cout<<"Size(Bits) " <<sizeInBits<<endl;
      cout<<"Signed: "<<(isSigned?"Yes":"No")<<endl;
      cout<<"Min Value: "<<minValue<<endl;
      cout<<"Max Value: "<<maxValue<<endl;
      cout<<"------------------------------"<<endl;
    }
};  

// Template Factory Function
template <typename T> 
Datatype createDatatype(string name) {
   return Datatype(name, sizeof(T), std::numeric_limits<T>::is_signed, std::numeric_limits<T>::lowest(), std::numeric_limits<T>::max() );
}


int main() {
  
  Datatype intType = createDatatype<int>("int");
  Datatype floatType = createDatatype<float>("float");
  Datatype doubleType = createDatatype<double>("double");

  intType.display();
  floatType.display();
  doubleType.display();
  
  return 0;

}
