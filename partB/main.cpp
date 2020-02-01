#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
string toBinary(int n)
{
  std::string r;
  while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
  while(r.length()< 8) {r = '0' + r;}
  return r;
}
vector<string> split(const std::string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string number;
  while(std::getline(ss, number, delim)) {
    number = toBinary(stoi(number));
    elems.push_back(number);
  }
  return elems;
}
vector<std::string> readfiles(const std::string& filename) {
  ifstream file(filename);
  vector<std::string> lines;
  if (!file) {
    cerr << "Cannot open file: " << filename << std::endl;
  } else {
    for (std::string line; std::getline(file, line);) {
      lines.push_back(line);
    }
    cout << std::to_string(lines.size()) << " lines read from [" << filename << "]" << std::endl;
  }
  return lines;
}
vector<vector<string>> BinaryIP(vector<string> stringIP){
  vector<vector<string>> BIP;
  for (int i = 0; i < stringIP.size(); i++){
    vector<string> temp = split(stringIP[i],'.');
    BIP.push_back(temp);
  }
  return  BIP;
}
int main(int argc, char *argv[]) {
  vector<string> ipList =readfiles(argv[2]);
  vector<vector<string>> binaryList = BinaryIP(ipList);
  cout<< binaryList[0][0] << " " <<binaryList[0][1] << " "<<binaryList[0][2] << " "<<binaryList[0][3] << endl;
  return 0;
}