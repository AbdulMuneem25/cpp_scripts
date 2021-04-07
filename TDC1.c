void TDC1(){

  std::string filename = "run8.root";
  TFile *f = new TFile(Form("%s", filename.c_str()));
  if(!f->IsOpen()){
    std::cout << " !- " << filename.c_str() << " is not found." << std::endl;
    exit(-1);
  }

  unsigned int Nhit;
  unsigned int tdc_leading[32];
  unsigned int Ch[32];
  TTree *tree = (TTree*)f->Get("tree");
  tree->SetBranchAddress("Nhit", &Nhit);
  tree->SetBranchAddress("tdc_leading", tdc_leading);
  tree->SetBranchAddress("Ch", Ch);

  TH1D *hnhit = new TH1D("nhit", "nhit", 10, 0, 10);
  TH1D *hch = new TH1D("ch", "ch", 64, 0, 64);
  TH1D *htd = new TH1D("timedifference","timedifference", 16, -10, 10);
  TH1D *hlead[4];
  for(int i=0; i<4; i++){
  hlead[i] = new TH1D(Form("lead%i",i), Form("lead%i",i), 200, 0, 200);
  }

  ///// event loop /////
  int nevent = tree->GetEntries();
  for(int ev=0; ev<nevent; ev++){
  tree->GetEntry(ev);
  hnhit->Fill(Nhit);


    int tdc1 = -999.;
    int tdc2 = -999.;
    int tdc3 = -999.;
    int tdc4 = -999.;
    for(int i=0; i<Nhit; i++){
      hch->Fill(Ch[i]);

      if(Ch[i]==44){
        tdc1 = tdc_leading[i];
      }else if(Ch[i]==45){
        tdc2 = tdc_leading[i];
      }else if(Ch[i]==46){
        tdc3 = tdc_leading[i];
      }else if(Ch[i]==47){
        tdc4 = tdc_leading[i];
      }

      hlead[0]->Fill(tdc1);
      hlead[1]->Fill(tdc2);
      hlead[2]->Fill(tdc3);
      hlead[3]->Fill(tdc4);

    }

    double timedifference = 0.83*(double(tdc3+tdc4)/2. - double(tdc1+tdc2)/2.);
    htd->Fill(timedifference);

    //std::cout << " nhit = " << Nhit << std::endl;
    //getchar();

  }

  TCanvas *c0 = new TCanvas("c0","c0",400,300);
  TCanvas *c1 = new TCanvas("c1","c1",400,300);
  c0->Divide(2,2);
  c1->Divide(2,2);
  c0->cd(1);
  hnhit->Draw();

  c0->cd(2);
  hch->Draw();

  c0->cd(3);
  htd->Draw();
  htd->Fit("gaus");

  for(int i=0; i<4; i++){
    c1->cd(i+1);
    hlead[i]->Draw();
    hlead[i]->Fit("gaus");
  }

  c0->Print("tdc.pdf(");
  c1->Print("tdc.pdf)");
}

