void henp14()
{
TFile *f= TFile::Open("run55.root");
TTreeReader test("tree", f);
TTreeReaderValue<UInt_t> nhit(test, "Nhit");
TH1D *h1 = new TH1D("h1","HIST",10,0,10);
while(test.Next()){
h1->Fill(*nhit);
}
h1->Fit("gaus");
h1->Draw();
}
