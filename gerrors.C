void gerrors() {

        TCanvas*c1 = new TCanvas("c1", "gerrors", 200,10,700,500);
        c1 ->SetGrid();
        TH1F *hr = c1->DrawFrame(0,10,0,30);
        hr ->SetXTitle("rotation");
        hr ->SetYTitle("intensity");
        c1->GetFrame()->SetBorderSize(1000);


        TGraph *gr1 = new TGraph("chiffres.txt");
        gr1 -> SetMarkerStyle(20);
        gr1 -> SetMarkerColor(kRed);
        gr1 -> Draw("LP");



}

