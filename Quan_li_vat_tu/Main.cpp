#include "Header.h"
#include "Common.h"
#include "Constant.h"
#include "Ss_page.h"
int main() {
	int x, y;
	
	initwindow(1200, 620,"Quan li vat tu");
	setbkcolor(bk_screen);
	cleardevice();
	createHeader(header_title);
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			// phat hien click chuot
			cout << "\nvi tri x:" << x << " - vi tri y:" << y << endl;
			// duong nay giup thay vi tri click
			line(x, y, x + 20, y);
			//code
			start:
			//Nhat
			
			//vat tu 
			if (ktVT(50, 10, 250, 50, x,y)) {
				createHeader(header_title);
				highlight_box(50, 10, 250, 50, header_title[0], f_medium, 3,10,56);
				g_page = true;
				sf_page = false;
				b_page = false;
				ss_page = false;
				delete_after_header();
			}
			if (g_page) {

			}
			// nhan vien
			if (ktVT(350, 10, 550, 50, x, y)) {
				createHeader(header_title);
				highlight_box(350, 10, 550, 50, header_title[1], f_medium, 3, 10, 43);
				g_page = false;
				sf_page = true;
				b_page = false;
				ss_page = false;
				delete_after_header();
			}
			if (sf_page) {

			}
			//Phu
			if (ktVT(650, 10, 850, 50, x, y)) {
				createHeader(header_title);
				highlight_box(650, 10, 850, 50, header_title[2], f_medium, 3, 10, 35);
				g_page = false;
				sf_page = false;
				b_page = true;
				ss_page = false;
				delete_after_header();
			}
			if (b_page) {



			}
			//Phuong
			if (ktVT(950, 10, 1150, 50, x, y)) {
				createHeader(header_title);
				highlight_box(950, 10, 1150, 50, header_title[3], f_medium, 3, 10, 45);
				g_page = false;
				sf_page = false;
				b_page = false;
				ss_page = true;
				delete_after_header();
			}
			if (ss_page) {
				create_ss_header();
				while (1) {
					if (ismouseclick(WM_LBUTTONDOWN)) {
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if (ktVT(15, 70, 310, 110, x, y)) {
							create_ss_header();
							highlight_box(15, 70, 310, 110, (char*)"Thong Ke Hoa Don", f_medium, 3, 10, 40);
							create_ss_search(1);
						}
						if (ktVT(320, 70, 565, 110, x, y)) {
							create_ss_header();
							highlight_box(320, 70, 565, 110, (char*)"Top 10 Vat Tu", f_medium, 3, 10, 40);
							create_ss_search(0);
						}
						if (ktVT(50, 10, 250, 50, x, y) || ktVT(350, 10, 550, 50, x, y) || ktVT(650, 10, 850, 50, x, y) || ktVT(950, 10, 1150, 50, x, y))
							goto start;
					}
				}
				//table_top_10_vattu();
			}

		}
		delay(1);
	}

		getch();
		closegraph();
	return 0;
}