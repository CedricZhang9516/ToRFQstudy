#define ONED
//#define TWOD

//const string draw = "save_px/save_pz:save_x-780";
//const string draw = "save_py/save_pz:save_y";

const string drawE = "save_ke*1000";
const string drawT = "det_time_start*1000";
const string drawX = "save_x-780";
const string drawY = "save_y";
const string cut  = "save_detID==654&&save_particleID==-13";

const int nf = 3;
const string filename[nf] =
  // {"data/highstat_150407.root",
  {"data/highstat_150407.root",
    //"data/tdr_cedric.root",
   //"data/tdr_cedric_D87000_T322_Nrepeat2000000_Xfree1_Thick7.12_NewGeo0_0828_3_2.root",
   //"data/musr_0.root"
  "data/Reflection-201201-1.root",
  "data/Reflection-201201-2.root"
  //"data/Reflection-201130-1.root"
   //"data/musr_0.root"
   //"data/tdr_cedric_D87000_T322_Nrepeat840000_Xfree1_Thick2.00_NewGeo1_0828_3.root"
   //"data/musr_0.root"
  };

TFile* fF[nf];
TTree* fT[nf];

TCanvas *c0,*c1,*c2,*c3,*c4,*c5;
#ifdef TWOD
TH2F*  fH[nf];
const int    xnbin = 60;
const double xmin  = -12;
const double xmax  = 12;
const int    ynbin = 60;
const double ymin  = -0.12;
const double ymax  = 0.12;
#endif
#ifdef ONED
TH1F*  fHe[nf];
TH1F*  fHt[nf];
TH1F*  fHx[nf];
TH1F*  fHy[nf];
//const int    xnbin = 100;
//const int    xnbin = 120;
const int    xnbin = 220;

//const double xmin  = 5.6;
//const double xmin  = 4.75;
const double xminE  = 5.00;
const double xmaxE  = 5.75;

/*
const double xmin  = 465;
const double xmax  = 490;
*/
//const double xminT  = 460;
const double xminT  = 360;
const double xmaxT  = 580;

/*
const double xmin  = 465;
const double xmax  = 520;
*/
const double ymin  = 0;
const double ymax  = 4000;
const string legname[nf] = {"TDR","With reflection model, muon acc by TDR HV","With reflection model, muon acc by TDR-revised HV"};//,"Otani-2018"};
//const string legname[nf] = {"TDR","Cedric (Geo0)", "Cedric (Geo1)"};
//const int fHstyle[nf]= {3552,3525};
const int fHstyle[nf]= {3350,3552,3525};
//const int fHstyle[nf]= {3001,3001,3001,3001};
//const int fHstyle[nf]= {3002,3002};
const int fHcolor[nf]= {1, 2, 4};
//const double scale[nf] = {12364./16967,1};
const double scale[nf] = {1,1,1};
#endif

const string xtitleE = "keV";
const string xtitleT = "ns";
//const string xtitle = "x (mm)";
//const string xtitle = "y (mm)";
//const string ytitle = "Events";

const string ytitle = "Normalized Events";
//const string ytitle = "x' (rad)";
//const string ytitle = "y' (rad)";
//const string title[nf] = {"Energy","",""};
//const string title[nf] = {"TDR","Cedric (Geo0)","Cedric (Geo1)"};
const string title[nf] = {"TDR","TDR HV","TDR-revised HV"};//,"Otani-2018"};
void macro_180823_compare_cedric(){

#ifdef TWOD
//gStyle->SetOptStat(1111);
//c1 = new TCanvas("c1","",10,10,1000,600);
 c1 = new TCanvas("c1","",10,10,1500,600);
  c1->Divide(nf,1);
  for(int i=0;i<nf; i++){
    c1 -> cd(i+1);
    fF[i] = new TFile(filename[i].c_str(), "read");
    fT[i] = (TTree*)fF[i]->Get("t1");

    fH[i] = new TH2F(Form("fH%d",i),"",xnbin, xmin, xmax, ynbin, ymin, ymax);
    fT[i]->Draw(Form("%s>>fH%d",draw.c_str(),i),cut.c_str(), "colz");
    //fT[i]->Draw(Form("%s>>fH%d(%d,%lf,%lf,%d,%lf,%lf)",draw.c_str(),i, xnbin, xmin, xmax, ynbin, ymin, ymax),cut.c_str(), "colz");
    fH[i]->GetXaxis()->SetRangeUser(xmin,xmax);
    fH[i]->GetYaxis()->SetRangeUser(ymin,ymax);
    fH[i]->SetXTitle(xtitle.c_str());
    fH[i]->SetYTitle(ytitle.c_str());
    fH[i]->SetTitle(title[i].c_str());
    fH[i]->Draw("colz");

    c1->Update();
    cin.get();
  }
  c1->cd();
  c1->Update();
#endif

#ifdef ONED



  gStyle->SetOptStat(0);

    c0 = new TCanvas("c0","");
    c5 = new TCanvas("c5","");c5->Divide(1,3);
    c4 = new TCanvas("c4","");c4->Divide(2,2);
  for(int i=0;i<nf; i++){
    fF[i] = new TFile(filename[i].c_str(), "read");
    fT[i] = (TTree*)fF[i]->Get("t1");

    fHe[i] = new TH1F(Form("fHe%d",i),"",xnbin, xminE, xmaxE);

    fT[i]->Project(Form("fHe%d",i),drawE.c_str(),cut.c_str() );
    //fT[i]->Draw(Form("%s>>fH%d",draw.c_str(),i),cut.c_str(), "");
    //fH[i]->GetXaxis()->SetRangeUser(xmin,xmax);

    fHe[i]->SetXTitle(xtitleE.c_str());
    fHe[i]->SetYTitle(ytitle.c_str());
    //fH[i]->SetNdivisions(606,"X");
    fHe[i]->SetFillStyle(fHstyle[i]);
    fHe[i]->SetFillColor(fHcolor[i]);
    fHe[i]->SetLineColor(fHcolor[i]);
    //fH[i]->Scale(scale[i]);
    fHe[i]->GetYaxis()->SetRangeUser(ymin,ymax);

    //if(i==0)
    //  fH[i]->Draw("C");
    //else
    //  fH[i]->Draw("same");
    //c0->Update();
    //cin.get();
  }
  c4->cd(1);
  fHe[0]->SetTitle("Ek at RFQ entrance");
  for(int i=0;i<nf; i++){
      if(i==0)
      fHe[i]->DrawNormalized("");
    else
      fHe[i]->DrawNormalized("same");
  }
  c0->cd();
  c0->Update();

  c1 = new TCanvas("c1","");
  for(int i=0;i<nf; i++){
    //fF[i] = new TFile(filename[i].c_str(), "read");
    //fT[i] = (TTree*)fF[i]->Get("t1");

    fHt[i] = new TH1F(Form("fHt%d",i),"",xnbin, xminT, xmaxT);

    fT[i]->Project(Form("fHt%d",i),drawT.c_str(),cut.c_str() );
    //fT[i]->Draw(Form("%s>>fH%d",draw.c_str(),i),cut.c_str(), "");
    //fH[i]->GetXaxis()->SetRangeUser(xmin,xmax);

    fHt[i]->SetXTitle(xtitleT.c_str());
    fHt[i]->SetYTitle(ytitle.c_str());
    //fH[i]->SetNdivisions(606,"X");
    fHt[i]->SetFillStyle(fHstyle[i]);
    fHt[i]->SetFillColor(fHcolor[i]);
    fHt[i]->SetLineColor(fHcolor[i]);
    //fH[i]->Scale(scale[i]);
    fHt[i]->GetYaxis()->SetRangeUser(ymin,ymax);

    //if(i==0)
    //  fH[i]->Draw("C");
    //else
    //  fH[i]->Draw("same");
    //c1->Update();
    //cin.get();
  }
  c4->cd(2);
  fHt[0]->SetTitle("Time at RFQ entrance");
  for(int i=0;i<nf; i++){
      if(i==0)
      fHt[i]->DrawNormalized("");
    else
      fHt[i]->DrawNormalized("same");
  }
  c1->cd();
  c1->Update();
  TLegend* leg = new TLegend(0.65,0.6,0.9,0.9);
  //TLegend* leg = new TLegend(0.25,0.6,0.55,0.9);
  leg -> SetShadowColor(0);
  leg -> SetFillColor(0);
  leg -> SetLineColor(0);
  for(int i=0; i<nf; i++)
    leg -> AddEntry(fHt[i],legname[i].c_str(),"f");
  c4->cd(1);
  leg->Draw();

#endif

  c2 = new TCanvas("c2","");

  for(int i=0;i<nf; i++){

    fHx[i] = new TH1F(Form("fHx%d",i),"",100,-40,40);
    //fT[i]->Project(Form("fHx%d",i),drawX.c_str(),cut.c_str() );
    fT[i]->Draw(Form("%s>>fHx%d",drawX.c_str(),i),cut.c_str());
    //fH[i]->GetXaxis()->SetRangeUser(xmin,xmax);
    fHx[i]->SetXTitle("X [mm]");
    fHx[i]->SetYTitle(ytitle.c_str());
    //fHx[i]->SetNdivisions(606,"X");
    //fHx[i]->SetFillStyle(fHstyle[i]);
    //fHx[i]->SetFillColor(fHcolor[i]);
    fHx[i]->SetLineColor(fHcolor[i]);
    //fHx[i]->Scale(scale[i]);
    //fHx[i]->GetYaxis()->SetRangeUser(ymin,ymax);

    if(i==0)
      fHx[i]->DrawNormalized("");
    else
      fHx[i]->DrawNormalized("same");
  }
  c4->cd(3);
  fHx[0]->SetTitle("X distribution at RFQ entrance");
  for(int i=0;i<nf; i++){
      if(i==0)
      fHx[i]->DrawNormalized("");
    else
      fHx[i]->DrawNormalized("same");
  }
  c2->cd();
  c2->Update();

  c3 = new TCanvas("c3","");
  c3->cd();

  for(int i=0;i<nf; i++){

    fHy[i] = new TH1F(Form("fHy%d",i),"",100,-40,40);
    fT[i]->Draw(Form("%s>>fHy%d",drawY.c_str(),i),cut.c_str());
    //fH[i]->GetXaxis()->SetRangeUser(xmin,xmax);
    fHy[i]->SetXTitle("Y [mm]");
    fHy[i]->SetYTitle(ytitle.c_str());
    //fHx[i]->SetNdivisions(606,"X");
    //fHy[i]->SetFillStyle(fHstyle[i]);
    //fHy[i]->SetFillColor(fHcolor[i]);
    fHy[i]->SetLineColor(fHcolor[i]);
    //fHy[i]->Scale(scale[i]);
    //fHx[i]->GetYaxis()->SetRangeUser(ymin,ymax);
    if(i==0)
      fHy[i]->Draw("");
    else
      fHy[i]->Draw("same");
  }
  c4->cd(4);
  fHy[0]->SetTitle("Y distribution at RFQ entrance");
  for(int i=0;i<nf; i++){
      if(i==0)
      fHy[i]->DrawNormalized("");
    else
      fHy[i]->DrawNormalized("same");
  }
  c3->Update();

  c5->cd(1);fHy[1-1]->Draw("");
  c5->cd(2);fHy[2-1]->Draw("");
  c5->cd(3);fHy[3-1]->Draw("");

};
