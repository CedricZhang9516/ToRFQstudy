//to answer the question at the review meeting

string filename = "dump_Mu.dat";
string output   = "test.root";
double x, xp, y, yp, tmp,e, z, t;
TFile* fF;
TTree* fT;
void Book(string filename){
  fF = new TFile(filename.c_str(), "recreate");
  fT = new TTree("tree","tree");
  fT -> Branch("x", &x, "x/D");
  fT -> Branch("y", &y, "y/D");
  fT -> Branch("z", &z, "z/D");
  fT -> Branch("xp", &xp, "xp/D");
  fT -> Branch("yp", &yp, "yp/D");
  fT -> Branch("e", &e, "e/D");
}
//____________________________
void Close(){
  fT -> Write();
  fF -> Write();
  fF -> Close();
}
//____________________________
void macro_161115_review_atLaser(){
  ifstream rf(filename.c_str());
  Book(output.c_str());
  while(rf >> x >> xp >> y >> yp >> e >> z >> t >> tmp >> tmp){
    fT -> Fill();
  }//while
  Close();  
}

void draw(){
  const int     nbin = 25;
  const double  zmin = 1; 
  const double  zmax = 6;

  TH1F* fH = new TH1F("fH", "", nbin, zmin, zmax);
  tree -> Project("fH", "z");
  fH -> SetXTitle("z[mm]");
  fH -> SetYTitle("# of muons(arb. unit)");
  fH -> GetYaxis() -> SetRangeUser(0,1700);
  fH -> SetFillColor(3);
  gStyle -> SetOptStat(0000);
  TCanvas* c1 = new TCanvas("c1","c1");

  fH -> Draw();
}


void draw_e(){
  const int     nbin = 25;
  const double  zmin = 0; 
  const double  zmax = 8e-6;

  TH1F* fH = new TH1F("fH", "", nbin, zmin, zmax);
  tree -> Project("fH", "e");
  fH -> SetXTitle("momentum (eV)]");
  fH -> SetYTitle("# of muons(arb. unit)");
  //fH -> GetYaxis() -> SetRangeUser(0,1700);
  fH -> SetFillColor(3);
  gStyle -> SetOptStat(0000);
  TCanvas* c1 = new TCanvas("c1","c1");

  fH -> Draw();
}
