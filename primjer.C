void primjer(){
   TCanvas *time = new TCanvas("c1","mion" ,600,1000);
   time ->cd(1);

   TH1F *h1 = new TH1F("h1","tdc kanal" ,4096,0,4096);
   ifstream in;
   Float_t t;
   Int_t nlines= 0;
   in.open("mion.txt", ios::in);
   while (1) {
      in >> t;
      if (!in.good()) break;
      h1->Fill(t);
      nlines++;
   }
   in.close();
   cout << nlines << endl;
   h1->Fit("gaus");
   h1->Draw();
}
