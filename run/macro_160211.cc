const string filename = "150417_muon_addT.txt";
string buf;
double E, Px, Py, Pz, X, Y, Z, T;
const double Toffset = 478;
const int nbin = 1000;
const double xmin = -10;
const double xmax = 10;
void macro_160211(){
  TH1F* fH = new TH1F("fH","fH",nbin,xmin,xmax);
  ifstream f(filename.c_str());
  getline(f,buf);
  while(f >> E >> Px >> Py >> Pz >> X >> Y >> Z >> T){
    T -= Toffset;
    fH -> Fill(T);    
  }
  fH -> Draw();
}
