void macro_150317(string fname){
  TFile* fF = new TFile("test.root","recreate");
  double ke, px, py, pz, x,y,z;
  TTree* fT = new TTree("tree","tree");
  fT -> Branch("ke", &ke, "ke/D");
  fT -> Branch("px", &px, "px/D");
  fT -> Branch("py", &py, "py/D");
  fT -> Branch("pz", &pz, "pz/D");
  fT -> Branch("x",  &x,  "x/D");
  fT -> Branch("y",  &y,  "y/D");
  fT -> Branch("z",  &z,  "z/D");
  ifstream rf(fname.c_str());
  string buf;
  getline(rf, buf);
  while(rf>>ke>>px>>py>>pz>>x>>y>>z)
    fT -> Fill();
  fT->Write();
  fF->Write();
  fF->Close(); 

}
