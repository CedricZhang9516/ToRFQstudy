void macro_150312_draw_focal(string filename){

  TFile* fF = new TFile(filename.c_str(), "read");
  gStyle -> SetOptStat(0000);
  TCanvas* c1 = new TCanvas("c1","c1",10,10,1200, 600);
  c1   -> Divide(2,1);
  c1   -> cd(1);
  tree -> Draw("fpx/fpz*1000:fx >> fHx0(1000,-5,5,1000, -100, 100)","flag==0&&id==-13");
  tree -> Draw("fpx/fpz*1000:fx >> fHx1(1000,-5,5,1000, -100, 100)", "flag==1&&id==-13", "same");
  fHx1 -> SetMarkerColor(2);
  fHx1 -> SetMarkerSize(0.3);
  fHx0 -> SetMarkerColor(1);
  fHx0 -> SetMarkerSize(0.3);
  fHx0 -> SetMarkerStyle(8);
  fHx1 -> SetMarkerStyle(8);

  fHx0 -> SetXTitle("x(mm)");
  fHx0 -> SetYTitle("p_{x}/p_{z}(mrad)");
  fHx0 -> SetTitle("X at focal");
  fHx0 -> Draw("p");
  fHx1 -> Draw("p:same");


  c1   -> cd(2);
  tree -> Draw("fpy/fpz*1000:fy >> fHy0(5000,-5,5,5000, -100, 100)","flag==0&&id==-13");
  tree -> Draw("fpy/fpz*1000:fy >> fHy1(5000,-5,5,5000, -100, 100)", "flag==1&&id==-13", "same");
  fHy1 -> SetMarkerColor(2);
  fHy1 -> SetMarkerSize(0.3);
  fHy0 -> SetMarkerColor(1);
  fHy0 -> SetMarkerSize(0.3);
  fHy0 -> SetMarkerStyle(8);
  fHy1 -> SetMarkerStyle(8);
  fHy0 -> SetXTitle("y(mm)");
  fHy0 -> SetYTitle("p_{y}/p_{z}(mrad)");
  fHy0 -> SetTitle("Y at focal");
  fHy0 -> Draw("p");
  fHy1 -> Draw("p:same");
  TLegend* leg = new TLegend(0.65,0.15, 0.92, 0.35);
  leg -> SetTextSize(0.05);

  TH1F* fHtmp1 = new TH1F("fHtmp1","fHtmp1",1,0,0.0001);
  fHtmp1 -> SetMarkerStyle(8);
  fHtmp1 -> SetMarkerColor(1);
  TH1F* fHtmp2 = new TH1F("fHtmp2","fHtmp2",1,0,0.0001);
  fHtmp2 -> SetMarkerStyle(8);
  fHtmp2 -> SetMarkerColor(2);
  fHtmp1->Draw("same:p");
  fHtmp2->Draw("same:p");

  leg -> AddEntry("fHtmp1", "All", "p");
  leg -> AddEntry("fHtmp2", "#splitline{within RFQ}{acceptance}", "p");
  leg -> SetShadowColor(0);
  leg -> SetLineColor(0);
  leg -> SetFillColor(0);
  leg -> Draw();
  c1-> cd();
}
