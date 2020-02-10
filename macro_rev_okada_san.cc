string inifile = "output_usm034a.dat";
string outfile = "okada-san.dat";
const double Mmu = 105.6583/1000;//GeV
void macro_rev_okada_san(){
  ifstream rf(inifile.c_str());
  ofstream wf(outfile.c_str());

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
