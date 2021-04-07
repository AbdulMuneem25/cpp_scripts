int ipad = 1;
TCanvas * c1 = 0;
void smooth_hist(const char * fname, double xmin, double xmax, int n1, int n2){
	std::cout<< "smoothing a" << fname << "histogram" << std::endl;
	TH1D * h1 = new TH1D("h1", "h1", 100, xmin, xmax);
	TH1D * h2 = new TH1D("h2","h2",100,xmin,xmax);
	h1->FillRandom(fname,n1);

	TH1D * h1_s = new TH1D(*h1);
	h1_s->SetName("h1_s");
	h1_s->Smooth();

	double p1 = h1->Chi2Test(h2, "");
	double p2 = h2->Chi2Test(h2,"UU");
	if (p2 < p1) Error("testSmooth","TH1::Smooth is not correctly-a oest chi2 is obtained");
	std::cout << " chi2 test non-smooth histo" << p1 << std::endl;
	std::cout << "chi2 test smooth histo" << p2 << std::endl;
	double a1 = h1->AndersonDarlingTest(h2);
	double a2 = h1_s->AndersonDarlingTest(h2);
	
	std::cout << " AD Test non-smooth histo" << a1 << std::endl;
	std::cout << " AD test smooth ratio" << a2 << std::endl;
	
	double k1 = h1->KolmogorovTest(h2);
	double k2 = h1_s->KolmogorovTest(h2);
	
	std::cout << "KS test non-smoothed hsito" << k1 << std::endl;
	std::cout << "KS test smoothed ratio" << k2 << std::endl;
	
	c1-> cd(ipad++);
	h1->Draw("E");
	h1_s->SetLineColor(kRed);
	h1_s->Draw("same");
	h2->Scale(double (n1)/n2);
	h2->SetLineColor(kGreen);
	h2->Draw("same");
}

void testsmooth(int n1 = 1000, int n2 = 1000000){
	TH1::AddDirectory(false);
	c1 = new TCanvas();
	c1->Divide(1,3);
	

	smooth_hist("gaus",-5,5,n1,n2);
	smooth_hist("landau",-5,15,n1,n2);
	smooth_hist("expo",-5,0,n1,n2);
}

	

