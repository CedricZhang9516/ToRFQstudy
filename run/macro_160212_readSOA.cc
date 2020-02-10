const string filename = "newSOA2_3D_map_v3.map";
string buf;
double x,y,z,Ex,Ey,Ez;
void macro_160212_readSOA(){
  ifstream rf(filename.c_str());
  for(int i=0; i<3; i++)getline(rf, buf);
  TGraph* fG = new TGraph()
  while( rf >> x >> y >> z >> Ex >> Ey >> Ez ){
    if(x!=0&&y!=0)continue;
  }//
}
