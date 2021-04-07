void histogram()
{

	TH1F *h1 = new TH1F("h1","histogram",1000,-5,5);
	TF1 *f1 = new TF1("f1", "[2]*TMath::Gaus(x,[0],[1])");
	f1->SetParameters(1,1,1);
	h1->FillRandom("f1");
	h1->Fit("gaus");
	h1->Draw();

}
