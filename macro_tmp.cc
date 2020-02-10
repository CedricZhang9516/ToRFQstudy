const int nbin = 100;
const double min = 0;
const double max = 0.00001;
const string filename = "test.dat";
void macro_tmp(){
  TH1F* fH = new TH1F("fH","fH",nbin, min, max);
  ifstream f(filename.c_str());
  double tmp, p;
  while(f>>tmp>>tmp>>tmp>>tmp>>p>>tmp>>tmp>>tmp>>tmp)
    fH -> Fill(p);
  fH ->Draw();
}
