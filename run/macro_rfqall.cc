TFile* fF;
TTree* fT;
double x, y, dx, dy, phase, ke;
const string filename = "test.root";
const string treename = "tree";
const string fname    = "rfqII.dsta";
void macro_rfqall(){
  fF = new TFile(filename.c_str(), "recreate");
  fT = new TTree(treename.c_str(), "");
  fT -> Branch("x",     &x,     "x/D");
  fT -> Branch("y",     &y,     "y/D");
  fT -> Branch("dx",    &dx,    "dx/D");
  fT -> Branch("dy",    &dy,    "dy/D");
  fT -> Branch("phase", &phase, "phase/D");
  fT -> Branch("ke",    &ke,    "ke/D");
  ifstream f(fname.c_str());
  while(f >> x >> dx >> y >> dy >> phase >> ke)
    fT -> Fill();

  fT -> Write();
  fF -> Write();
  fF -> Close();

}
