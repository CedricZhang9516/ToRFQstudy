const string inifile = "../output_usm034a.dat";
const string outfile = "result.dat";
const string rootname = "data/okada-san_check_same_data.root";
const double Mmu = 105.6583/1000;//GeV
void macro_rev_okada_san(){
  ifstream rf(inifile.c_str());
  ofstream wf(outfile.c_str());
  TFile* fF = new TFile(rootname.c_tr(), "read");
  TTree* fT = (TTree*)fF->Get("t1");
  double save_px, save_py, save_pz, save_x, save_y;
  fT -> SetBranchAddress("save_px", &save_px);

  double  x,y,z,vx,vy,vz,en, fx,fy,fz,fvx,fvy,fvz,ft;
  while( rf>>x>>y>>z>>vx>>vy>>vz>>en>> fx>>fy>>fz>>fvx>>fvy>>fvz>>ft ){
    double v = sqrt(vx*vx+vy*vy+vz*vz);
    double en_ = en * 1e-9;
    double p = sqrt(2.0*Mmu*en_ + en_*en_);
    wf << x*0.1 << " "
       << TMath::ASin(vx/v)*1000 << " "
       << y*0.1 << " "
       << TMath::ASin(vy/v)*1000 << " "


       << p << " "
       << z << " "
       << 0 << " "
       << "-1 -1" << endl;
  }

}
