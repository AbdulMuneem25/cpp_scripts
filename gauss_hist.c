void gauss_hist()
{

	THStack *hs = new THStack("hs","1d colored histogram");
	gStyle->SetPalette(kOcean);
	

	TH1F * h1st = new TH1F("h1st", "test hstack", 100,-4,4);
	h1st->FillRandom("gaus", 20000);
	h1st->Fit("gaus");
	hs->Add(h1st);
	TH1F *h2st = new TH1F("h2st","test hstack",100,-4,4);
	h2st->FillRandom("gaus",15000);
	hs->Add(h2st);
	h2st->Fit("gaus");
	TH1F *h3st = new TH1F("h3st","test hstack",100,-4,4);
	h3st->FillRandom("gaus",10000);
	hs->Add(h3st);	
	h3st->Fit("gaus");
	hs->Draw("hfc nostack");

}
