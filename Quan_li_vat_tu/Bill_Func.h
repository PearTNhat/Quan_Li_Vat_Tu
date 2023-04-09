﻿#pragma once
#include "Header.h"
#include "Common.h"
#include "Constant.h"
#include "Bill_Struct.h"
#include "input_bill.h"
#include "Staff_func.h"

view_page vp_m_ss;
string soHD = "";

char sohoadon[21] = "HD";
char mavattu[11] = "VT";

void b_taokhungxanhla(int l, int t, int r, int b)
{
	setcolor(10);
	rectangle(l, t, r, b);
}

void b_taokhungden(int l, int t, int r, int b)
{
	setcolor(0);
	rectangle(l, t, r, b);
}

void b_duongthang(int x1, int y1, int x2, int y2)
{
	setcolor(10);
	line(x1, y1, x2, y2);
}

void b_create_menu_title()
{
	setfillstyle(1, bk_screen);
	setcolor(0);
	//bar3d(10, 65, 1180, 115, 0, 0);
	text_box(15, 70, 310, 110, (char*)"Lap hoa don", f_medium, 3, 10, 40, XANH_DUONG_NHAT);
	text_box(350, 70, 645, 110, (char*)"Tra hang", f_medium, 3, 10, 40, XANH_DUONG_NHAT);
	text_box(685, 70, 980, 110, (char*)"In hoa don", f_medium, 3, 10, 40, XANH_DUONG_NHAT);
	
	//b_taokhungden(10, 120, 1180, 600);
}

void b_delete_after_create() {
	setfillstyle(1, bk_screen);
	bar(0, 121, 1200, 599);
}

void b_create_NX()
{
	b_taokhungden(10, 120, 110, 220);
	text_box(20, 130, 100, 170, (char*)"N", f_medium, 3, 10, 30, 9);
	text_box(20, 170, 100, 210, (char*)"X", f_medium, 3, 10, 30, 9);
}

void b_create_info()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string curr_date = to_string(ltm->tm_mday);
	string curr_month = to_string(1 + ltm->tm_mon);
	string curr_year = to_string(1900 + ltm->tm_year);

	text_box(110, 120, 590, 145, (char*)"So hoa don:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 145, 270, 170, (char*)"ngay:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(180, 146, 265, 168, (char*)curr_date.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(270, 145, 430, 170, (char*)"thang:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(350, 146, 425, 168, (char*)curr_month.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(430, 145, 590, 170, (char*)"nam:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(480, 146, 585, 168, (char*)curr_year.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(590, 120, 980, 145, (char*)"Ma nhan vien:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 170, 430, 195, (char*)"Ma vat tu:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 195, 350, 220, (char*)"So luong:", f_medium, 2, 1, 5, 9, 0);
	text_box(350, 195, 590, 220, (char*)"Don gia:", f_medium, 2, 1, 5, 9, 0);
	text_box(430, 170, 590, 195, (char*)"%VAT: ", f_medium, 2, 1, 5, 9, 0);
	text_box(620, 145, 770, 170, (char*)"Them vat tu", f_medium, 2, 1, 5, 11, 0);
	text_box(800, 145, 950, 170, (char*)"Luu hoa don", f_medium, 2, 1, 5, 11, 0);
	text_box(590, 170, 980, 195, (char*)"Trang thai", f_medium, 2, 1, 135, 9, 0);
	text_box(590, 195, 740, 220, (char*)"1:khach mua", f_medium, 2, 1, 1, 9, 0);
	text_box(740, 195, 980, 220, (char*)"0:khach da tra hang", f_medium, 2, 1, 1, 9, 0);
	text_box_no_border(985, 125, 1175, 215, (char*)"", f_medium, 2, 1, 5, 14, 0);

	b_taokhungden(10, 120, 110, 220);
	b_taokhungden(110, 120, 980, 220);
	b_taokhungden(980, 120, 1180, 220);
}

void b_giaodiennhd(int& x, int& y)
{
	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (ktVT(110, 120, 590, 145, x, y))
			{
				//SoHD
				string d = input_bill(x, y, 250, 121, 588, 143, 5, 3, 985, 125, 1175, 215, "", 20, "number", "upcase");
			}
			if (ktVT(110, 145, 270, 170, x, y))
			{
				//ngay
				string d = input_bill(x, y, 175, 146, 268, 168, 5, 3, 985, 125, 1175, 215, "", 2, "number", "calmCase");
			}
			if (ktVT(270, 145, 430, 170, x, y))
			{
				//thang
				string d = input_bill(x, y, 345, 146, 428, 168, 5, 3, 985, 125, 1175, 215, "", 2, "number", "calmCase");
			}
			if (ktVT(430, 145, 590, 170, x, y))
			{
				//nam
				string d = input_bill(x, y, 480, 146, 588, 168, 5, 3, 985, 125, 1175, 215, "", 2, "number", "calmCase");
			}
			if (ktVT(590, 120, 980, 145, x, y))
			{
				//maNV
				string d = input_bill(x, y, 750, 121, 978, 143, 5, 3, 985, 125, 1175, 215, "", 10, "number", "calmCase");
			}
			if (ktVT(110, 170, 430, 195, x, y))
			{
				//MAVT
				string d = input_bill(x, y, 235, 171, 428, 193, 5, 3, 985, 125, 1175, 215, "", 10, "textNumberNoSpace", "calmCase");
			}
			if (ktVT(110, 195, 350, 220, x, y))
			{
				//Soluong
				string d = input_bill(x, y, 220, 196, 348, 218, 5, 3, 985, 125, 1175, 215, "", 5, "number", "calmCase");
			}
			if (ktVT(350, 195, 590, 220, x, y))
			{
				//Dongia
				string d = input_bill(x, y, 450, 196, 588, 218, 5, 3, 985, 125, 1175, 215, "", 7, "number", "calmCase");
			}
			if (ktVT(430, 170, 590, 195, x, y))
			{
				//VAT
				string d = input_bill(x, y, 495, 171, 588, 193, 5, 3, 985, 125, 1175, 215, "", 2, "number", "calmCase");
			}
			if (ktVT(590, 195, 740, 220, x, y))
			{
				//1: khach mua
				text_box(590, 195, 740, 220, (char*)"1:khach mua", f_medium, 2, 1, 1, I_HIGHLIGHT, 0);
			}
			if (ktVT(740, 195, 980, 220, x, y))
			{
				//0 khach da tra hang
				text_box(740, 195, 980, 220, (char*)"0:khach da tra hang", f_medium, 2, 1, 1, I_HIGHLIGHT, 0);
			}
			if (ktVT(620, 165, 770, 190, x, y))
			{
				//b_create_info();
				//highlight_box(620, 165, 770, 190, (char*)"Them vat tu", f_medium, 2, 1, 5, 0, 10);
			}
			if (ktVT(800, 165, 950, 190, x, y))
			{
				//b_create_info();
				//highlight_box(800, 165, 950, 190, (char*)"Luu hoa don", f_medium, 2, 1, 5, 0, 10);
			}



			if (ktVT(50, 10, 250, 50, x, y)   ||
				ktVT(350, 10, 550, 50, x, y)  ||
				ktVT(650, 10, 850, 50, x, y)  ||
				ktVT(950, 10, 1150, 50, x, y) ||
				ktVT(15, 70, 310, 110, x, y)  ||
				ktVT(350, 70, 645, 110, x, y) ||
				ktVT(685, 70, 980, 110, x, y) ||
				ktVT(20, 130, 100, 170, x, y) ||
				ktVT(20, 170, 100, 210, x, y))
			{
				break;
			}
		}
	}
}

void HIGHTLIGHT_ADD_VT(int& x, int& y)
{
	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			{
				if (ktVT(620, 165, 770, 190, x, y))
				{
					
					highlight_box(620, 165, 770, 190, (char*)"Them vat tu", f_medium, 2, 1, 5, 14, 0);
				}
				if (ktVT(50, 10, 250, 50, x, y) ||
					ktVT(350, 10, 550, 50, x, y) ||
					ktVT(650, 10, 850, 50, x, y) ||
					ktVT(950, 10, 1150, 50, x, y) ||
					ktVT(15, 70, 310, 110, x, y) ||
					ktVT(350, 70, 645, 110, x, y) ||
					ktVT(685, 70, 980, 110, x, y) ||
					ktVT(20, 130, 100, 170, x, y) ||
					ktVT(20, 170, 100, 210, x, y))
				{
					break;
				}

			}
		}
	}
}

void HIGHTLIGHT_ADD_HD(int& x, int& y)
{
	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			{
				if (ktVT(620, 165, 770, 190, x, y))
				{
					highlight_box(800, 165, 950, 190, (char*)"Luu hoa don", f_medium, 2, 1, 5, 0, 10);
				}
				if (ktVT(50, 10, 250, 50, x, y) ||
					ktVT(350, 10, 550, 50, x, y) ||
					ktVT(650, 10, 850, 50, x, y) ||
					ktVT(950, 10, 1150, 50, x, y) ||
					ktVT(15, 70, 310, 110, x, y) ||
					ktVT(350, 70, 645, 110, x, y) ||
					ktVT(685, 70, 980, 110, x, y) ||
					ktVT(20, 130, 100, 170, x, y) ||
					ktVT(20, 170, 100, 210, x, y))
				{
					break;
				}

			}
		}
	}
}



//void create_bill_tabble()
//{
//
//}






//Tra hang

void b_create_gdtrahang() {
	//text_box(350, 150, 850, 200, (char*)"Vui long nhap so hoa don muon tra hang:", f_medium, 2, 15, 20, 9, 0);
	text_box_no_border(350, 150, 850, 200, (char*)"Vui long nhap so hoa don muon tra hang:", f_medium, 2, 15, 20, 9, 0);

	settextstyle(f_medium, 0, 4);
	setbkcolor(I_BG);
	outtextxy(300, 325, (char*)"So hoa don:");

	
	b_taokhungden(250, 200, 950, 500);
	b_taokhungden(550, 325, 900, 355);

	text_box(525, 450, 675, 500, (char*)"Kiem tra", f_medium, 2, 15, 20, 11, 0);
}

bool checktrungshd(DS_NhanVien& ds_nv, DS_HoaDon& ds_hdP, string d)
{
	read_file_staff(ds_nv, ds_hdP);
	for (int i = 0; i < ds_nv.length; i++)
	{
		DS_HoaDon* curr_hd = ds_nv.nhan_vien[i]->ds_hoadon; // trỏ đến danh sách hóa đơn của nhân viên hiện tại
		while (curr_hd != NULL) // duyệt từng hóa đơn trong danh sách
		{
			if (stoi(string(curr_hd->hoadon.SoHD).substr(2)) == stoi(string(d))) // nếu trùng số hóa đơn
			{
				return false; // trả về false
			}
			curr_hd = curr_hd->next; // chuyển đến hóa đơn tiếp theo trong danh sách
		}
	}
	return true; // nếu không trùng thì trả về true
}

bool checktrungmavt(DS_VatTu* root, string x)
{
	DS_VatTu* p = root;
	while (p != NULL && stoi(string(p->vat_tu.maVT).substr(2)) != stoi(string(x).substr(2)))
	{
		if (stoi(string(x).substr(2)) > stoi(string(p->vat_tu.maVT).substr(2)))
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	if (p == NULL)
	{
		return false;
	}
	return true;
}


void resetbaoloi()
{
	text_box_no_border(985, 125, 1175, 215, (char*)"", f_medium, 2, 1, 5, 14, 0);
}

void in_hoa_don_table (
	char table_in_HD_header[][20],
	DS_HoaDon* nodeHD,
	view_page& view_page,
	int num_per_pg
) {
	b_delete_after_create();
	b_create_menu_title();

	// tinh so page co trong trang

	DS_CT_HoaDon* ds = nodeHD->hoadon.first_cthd;

	int n = getNumOfCTHD(ds);
	int page = n / num_per_pg;
	int du = n % num_per_pg;
	view_page.page = du ? page + 1 : page;
	int max_rows = n > (num_per_pg * view_page.current) ? (num_per_pg * view_page.current) : n;
	// reder page
	int i = num_per_pg * (view_page.current - 1);
	setfillstyle(1, 15);
	bar(0, 121, 1200, 800);
	// create table title
	writeText(10, 130, (char*)"CONG TY TNHH NHAT PHU PHUONG", 3, COLOR(51, 51, 51), f_medium, 15);
	writeText(800 ,130, (char*)"HOA DON BAN HANG", 4, COLOR(51, 51, 51), BOLD_FONT, 15); // bk_screen
	// create bar	
	//setlinestyle(0, 0, 2);
	rectangle (-2, 160, 500, 290);
	rectangle(500, 160, 1200, 290);
	setfillstyle(1, COLOR(221, 221, 221));
	setbkcolor(COLOR(221, 221, 221));
	bar(-2, 161, 500, 200);
	settextstyle(3, 0, 3);
	string soHD = "No:  ";
	soHD += nodeHD->hoadon.SoHD;
	outtextxy(10, 170, (char*)soHD.c_str());
	setbkcolor(15);
	line(0, 200, 500, 200);
	string date = "Ngay lap:  ";
	date += to_string(nodeHD->hoadon.date.ngay);
	date += " / ";
	date += to_string(nodeHD->hoadon.date.thang);
	date += " / ";
	date += to_string(nodeHD->hoadon.date.nam);
	outtextxy(10, 213, (char*)date.c_str());
	string loai;
	if (!strcmp(nodeHD->hoadon.Loai, "N")) loai = "Loai:  Hoa don nhap";
	else loai = "Loai:  Hoa don xuat";
	outtextxy(10, 250, (char*)loai.c_str());
	// header num_rows
	int bar_top = 300, bar_bottom = 332;
	int text_top = 305;
	setcolor(0);
	setfillstyle(1, COLOR(221, 221, 221));
	setbkcolor(COLOR(221, 221, 221));
	bar3d(0, bar_top, 1200, bar_bottom, 0, 0);
	setcolor(0);
	settextstyle(f_small, 0, 2);
	outtextxy(55, text_top, (char*)"STT");
	outtextxy(130, text_top, table_in_HD_header[0]);
	outtextxy(270, text_top, table_in_HD_header[1]);
	outtextxy(470, text_top, table_in_HD_header[2]);
	outtextxy(660, text_top, table_in_HD_header[3]);
	outtextxy(830, text_top, table_in_HD_header[4]);
	outtextxy(1000, text_top, table_in_HD_header[5]);
	setfillstyle(1, 15);
	setbkcolor(15);
	for (; i < max_rows; i++)
	{
		if (i % num_per_pg == 0) {
			bar_top += 30;
			bar_bottom += 40;
			text_top += 35;
		}
		else {
			bar_top += 40;
			bar_bottom += 40;
			text_top += 40;
		}
		// row
		setcolor(0);
		bar3d(0, bar_top, 1200, bar_bottom, 0, 0);
		// title header
		char stt[10];
		strcpy_s(stt, to_string(i + 1).c_str());
		writeText(70, text_top, stt, 1, 0, 3, 15);
		DS_CT_HoaDon* tempNodeCT = getIndexCTHD(ds, i);
		writeText(135, text_top, tempNodeCT->ct_hoadon.MAVT, 1, 0, 3, 15);
		string soluong = to_string(tempNodeCT->ct_hoadon.Soluong);
		writeText(284, text_top, (char*)soluong.c_str(), 1, 0, 3, 15);
		string dongia = formatNumber(tempNodeCT->ct_hoadon.Dongia);
		writeText(470, text_top, (char*)dongia.c_str(), 1, 0, 3, 15);
		stringstream s;
		s << tempNodeCT->ct_hoadon.VAT;
		string VAT = s.str();
		writeText(680, text_top, (char*)VAT.c_str(), 1, 0, 3, 15);
		if (tempNodeCT->ct_hoadon.TrangThai == 1) 
			writeText(833, text_top, (char*)"Khach mua", 1, 0, 3, 15);
		else 
			writeText(833, text_top, (char*)"Khach tra", 1, 0, 3, 15);
		cout << "VAT: " << tempNodeCT->ct_hoadon.VAT << endl;
		int thanhtien = (tempNodeCT->ct_hoadon.Soluong * tempNodeCT->ct_hoadon.Dongia) + (tempNodeCT->ct_hoadon.Soluong * tempNodeCT->ct_hoadon.Dongia * tempNodeCT->ct_hoadon.VAT/100);
		writeText(1010, text_top, (char*)formatNumber(thanhtien).c_str(), 1, 0, 3, 15);
	}

	// < >
	page_transition(view_page, true);
}

void handle_in_HD_table(int& x, int& y, DS_HoaDon* ds) {
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			// transition page
			if (ktVT(650, 565, 685, 600, x, y)) {
				if (vp_m_ss.current == vp_m_ss.page) {
					continue;
				}
				next_page(650, 565, 685, 600, vp_m_ss);

				delete_after_header();
				in_hoa_don_table(ss_table_header, ds, vp_m_ss, ROWS_PER_PG_SS);
			}
			if (ktVT(495, 565, 530, 600, x, y)) {
				if (vp_m_ss.current == 1) {
					continue;
				}
				prev_page(495, 565, 530, 600, vp_m_ss);
				delete_after_header();
				in_hoa_don_table(ss_table_header, ds, vp_m_ss, ROWS_PER_PG_SS);
			}
			if (ktVT(50, 10, 250, 50, x, y) || ktVT(350, 10, 550, 50, x, y) || ktVT(650, 10, 850, 50, x, y) || ktVT(950, 10, 1150, 50, x, y)) {
				ss_page = false;
				goto ss_end;
			}
			if (ktVT(15, 70, 310, 110, x, y) || ktVT(320, 70, 640, 110, x, y)) {
				// reset view_page
				vp_m_ss.current = 1;
				vp_m_ss.page = 1;
				out_table = true;
				goto ss_end;
			}
		}
		delay(1);
	}
ss_end:;
}

void xu_li_tra_cuu_hoa_don(int& x, int& y, bool& error_sohd, string& soHD, bool page, DS_NhanVien ds_nv) {
	if (ktVT(620, 285, 845, 320, x, y) && page) {
		cout << "Tien hanh nhap input SoHD";
		soHD = input_soHD(error_sohd, x, y, 620, 285, 845, 320, 70, 7, 5, 45, 50, soHD, 10, "textNumberNoSpace", "upcase", COLOR_INFOR_SS, 430, 225);
	}
	if (error_sohd) return;
	if (ktVT(450, 410, 750, 450, x, y) && page) {
		cout << "Click button tim kiem" << endl;
		// check empty 
		if (soHD == "") {
			cout << "Input so hoa don empty" << endl;
		}
		else {
			cout << "Tien hanh kiem tra so hoa don" << endl;
			DS_HoaDon* result_HD = new DS_HoaDon();
			result_HD = NULL;
			for (int i = 0; i < ds_nv.length; i++) {
				NhanVien* nv = ds_nv.nhan_vien[i];
				DS_HoaDon* nodeHD = nv->ds_hoadon;
				while (nodeHD != NULL && strcmp(nodeHD->hoadon.SoHD, soHD.c_str())) nodeHD = nodeHD->next;
				if (nodeHD != NULL) {
					result_HD = nodeHD;
					break;
				}
			}
			if (result_HD == NULL) {
				writeText(460, 370, (char*)"So hoa don khong ton tai!", 2, COLOR(255, 0, 0), 8, COLOR_INFOR_SS);
			}
			else {
				writeText(490, 370, (char*)"OK! Lap bang", 2, COLOR(255, 0, 0), 8, COLOR_INFOR_SS);
				in_hoa_don_table(table_in_HD_header, result_HD, vp_m_ss, 5);
			}
		}
	}
}


void do_hoa_in_hoadon(bool& is_error) {
	setfillstyle(1, COLOR_INFOR_SS);
	setcolor(0);
	bar3d(280, 180, 920, 490, 0, 0);

	// Thanh tieu de
	setlinestyle(0, 0, 1);
	const char* title = "IN HOA DON";
	text_box(470, 140, 720, 181, (char*)title, 10, 3, 10, 58, COLOR(51, 51, 51), 15); // font 8
	// Thanh tim kiemi
	text_box(450, 410, 750, 450, (char*)"Tìm hóa đơn", f_medium, 3, 10, 70, COLOR(255, 153, 51), 0);
	// User input 
	setfillstyle(1, 15);
	setbkcolor(COLOR_INFOR_SS);
	outtextxy(360, 290, (char*)"Nhap so hoa don:");
	bar3d(620, 285, 845, 320, 0, 0);
}

void nhd(int& x, int& y)
{
	DS_NhanVien ds_nv;
	DS_HoaDon ds_hdP;
	DS_VatTu* ds_vt;

	bool nhap = false, xuat = false;
	bool sohd = false, manv = false, mavt = false, soluong = false, dongia = false, vat = false, trangthai;

	read_file_staff(ds_nv, ds_hdP);
	//read_file_goods(ds_vt);

	time_t now = time(0);
	tm* ltm = localtime(&now);
	string curr_date = to_string(ltm->tm_mday);
	string curr_month = to_string(1 + ltm->tm_mon);
	string curr_year = to_string(1900 + ltm->tm_year);

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (ktVT(110, 120, 590, 145, x, y))
			{
				resetbaoloi();
				//SoHD
			sohd:
				string d = input_bill(x, y, 250, 121, 588, 143, 5, 3, 985, 125, 1175, 215, "", 20, "number", "upcase");
				if (empty(d) == true) goto sohd;
				while (checktrungshd(ds_nv, ds_hdP, d) == false)
				{
					text_box(985, 125, 1175, 215, (char*)"Loi!Trung SoHD", f_medium, 2, 30, 8, RED, 0, 0);
					text_box(110, 120, 590, 145, (char*)"So hoa don:", f_medium, 2, 1, 5, 9, 0);
					goto sohd;
				}
				if (checktrungshd(ds_nv, ds_hdP, d) == true)
				{
					text_box(985, 125, 1175, 215, (char*)"OK!", f_medium, 2, 30, 8, LIGHTGREEN, 0, 0);

				}
				strcat(sohoadon, d.c_str());

			}
			if (ktVT(590, 120, 980, 145, x, y))
			{
				resetbaoloi();
				//maNV

				string d = input_bill(x, y, 750, 121, 978, 143, 5, 3, 985, 125, 1175, 215, "", 10, "number", "calmCase");

			}
			if (ktVT(110, 170, 430, 195, x, y))
			{
				//MAVT
				resetbaoloi();
			mavt:
				string d = input_bill(x, y, 235, 171, 428, 193, 5, 3, 985, 125, 1175, 215, "", 10, "textNumberNoSpace", "calmCase");
				/*if (empty(d) == true) goto mavt;
				while (checktrungmavt(ds_vt, d) == false)
				{
					text_box(985, 125, 1175, 215, (char*)"Ko ton tai VT!", f_medium, 2, 30, 8, RED, 0, 0);
					text_box(110, 170, 430, 195, (char*)"Ma vat tu:", f_medium, 2, 1, 5, 9, 0);
					goto mavt;
				}
				if (checktrungmavt(ds_vt, d) == true)
				{
					text_box(985, 125, 1175, 215, (char*)"OK!", f_medium, 2, 30, 8, LIGHTGREEN, 0, 0);
				}
				strcat(mavattu, d.c_str());*/
			}
			if (ktVT(110, 195, 350, 220, x, y))
			{
				//Soluong
				string d = input_bill(x, y, 220, 196, 348, 218, 5, 3, 985, 125, 1175, 215, "", 5, "number", "calmCase");
			}
			if (ktVT(350, 195, 590, 220, x, y))
			{
				//Dongia
				string d = input_bill(x, y, 450, 196, 588, 218, 5, 3, 985, 125, 1175, 215, "", 7, "number", "calmCase");
			}
			if (ktVT(430, 170, 590, 195, x, y))
			{
				//VAT
				string d = input_bill(x, y, 495, 171, 588, 193, 5, 3, 985, 125, 1175, 215, "", 2, "number", "calmCase");
			}
			if (ktVT(590, 195, 740, 220, x, y))
			{
				//1: khach mua
				text_box(590, 195, 740, 220, (char*)"1:khach mua", f_medium, 2, 1, 1, I_HIGHLIGHT, 0);
			}
			if (ktVT(740, 195, 980, 220, x, y))
			{
				//0 khach da tra hang
				text_box(740, 195, 980, 220, (char*)"0:khach da tra hang", f_medium, 2, 1, 1, I_HIGHLIGHT, 0);
			}
			if (ktVT(620, 165, 770, 190, x, y))
			{
				//b_create_info();
				//highlight_box(620, 165, 770, 190, (char*)"Them vat tu", f_medium, 2, 1, 5, 0, 10);
			}
			if (ktVT(800, 165, 950, 190, x, y))
			{
				//b_create_info();
				//highlight_box(800, 165, 950, 190, (char*)"Luu hoa don", f_medium, 2, 1, 5, 0, 10);
			}



			if (ktVT(50, 10, 250, 50, x, y) ||
				ktVT(350, 10, 550, 50, x, y) ||
				ktVT(650, 10, 850, 50, x, y) ||
				ktVT(950, 10, 1150, 50, x, y) ||
				ktVT(15, 70, 310, 110, x, y) ||
				ktVT(350, 70, 645, 110, x, y) ||
				ktVT(685, 70, 980, 110, x, y) ||
				ktVT(20, 130, 100, 170, x, y) ||
				ktVT(20, 170, 100, 210, x, y))
			{
				break;
			}
		}
	}
}

void nhd_bill(int& x, int& y)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string curr_date = to_string(ltm->tm_mday);
	string curr_month = to_string(1 + ltm->tm_mon);
	string curr_year = to_string(1900 + ltm->tm_year);

	b_create_menu_title();
	highlight_box(15, 70, 310, 110, (char*)"Lap hoa don", f_medium, 3, 10, 40, 14, 0);
	b_delete_after_create();

	b_taokhungden(10, 120, 110, 220);
	text_box(20, 130, 100, 170, (char*)"N", f_medium, 3, 10, 30, 9);
	text_box(20, 170, 100, 210, (char*)"X", f_medium, 3, 10, 30, 9);

	text_box(110, 120, 590, 145, (char*)"So hoa don:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 145, 270, 170, (char*)"ngay:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(180, 146, 265, 168, (char*)curr_date.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(270, 145, 430, 170, (char*)"thang:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(350, 146, 425, 168, (char*)curr_month.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(430, 145, 590, 170, (char*)"nam:", f_medium, 2, 1, 5, 9, 0);
	text_box_no_border(480, 146, 585, 168, (char*)curr_year.c_str(), f_medium, 2, 1, 5, 9, 0);
	text_box(590, 120, 980, 145, (char*)"Ma nhan vien:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 170, 430, 195, (char*)"Ma vat tu:", f_medium, 2, 1, 5, 9, 0);
	text_box(110, 195, 350, 220, (char*)"So luong:", f_medium, 2, 1, 5, 9, 0);
	text_box(350, 195, 590, 220, (char*)"Don gia:", f_medium, 2, 1, 5, 9, 0);
	text_box(430, 170, 590, 195, (char*)"%VAT: ", f_medium, 2, 1, 5, 9, 0);
	text_box(620, 145, 770, 170, (char*)"Them vat tu", f_medium, 2, 1, 5, 11, 0);
	text_box(800, 145, 950, 170, (char*)"Luu hoa don", f_medium, 2, 1, 5, 11, 0);
	text_box(590, 170, 980, 195, (char*)"Trang thai", f_medium, 2, 1, 135, 9, 0);
	text_box(590, 195, 740, 220, (char*)"1:khach mua", f_medium, 2, 1, 1, 9, 0);
	text_box(740, 195, 980, 220, (char*)"0:khach da tra hang", f_medium, 2, 1, 1, 9, 0);
	text_box_no_border(985, 125, 1175, 215, (char*)"", f_medium, 2, 1, 5, 14, 0);

	b_taokhungden(10, 120, 110, 220);
	b_taokhungden(110, 120, 980, 220);
	b_taokhungden(980, 120, 1180, 220);

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
		NX:
			if (!ktVT(20, 130, 100, 170, x, y) || !ktVT(20, 170, 100, 210, x, y))
			{
				text_box(985, 125, 1175, 215, (char*)"xin chon N/X", f_medium, 2, 30, 8, RED, 0, 0);
			}

			if (ktVT(20, 130, 100, 170, x, y))
			{
				b_create_NX();
				highlight_box(20, 130, 100, 170, (char*)"N", f_medium, 3, 10, 30, 14, 0);
				b_create_info();
				nhd(x, y);
			}
			if (ktVT(20, 170, 100, 210, x, y))
			{
				b_create_NX();
				highlight_box(20, 170, 100, 210, (char*)"X", f_medium, 3, 10, 30, 14, 0);
				b_create_info();
				b_giaodiennhd(x, y);
				goto NX;
			}
			if (ktVT(50, 10, 250, 50, x, y) ||
				ktVT(350, 10, 550, 50, x, y) ||
				ktVT(650, 10, 850, 50, x, y) ||
				ktVT(950, 10, 1150, 50, x, y) ||
				ktVT(15, 70, 310, 110, x, y) ||
				ktVT(350, 70, 645, 110, x, y) ||
				ktVT(685, 70, 980, 110, x, y))
			{
				break;
			}
		}
		delay(1);
	}

}

void bill_page(int& x, int& y, DS_NhanVien ds_nv)
{
	bool error_soHD = false;
	bool in_hoa_don_page = false;
	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
		batdau:
			if (ktVT(15, 70, 310, 110, x, y))
			{
				nhd_bill(x, y);
				goto batdau;
			}
			if (ktVT(350, 70, 645, 110, x, y))
			{
				b_create_menu_title();
				highlight_box(350, 70, 645, 110, (char*)"Tra hang", f_medium, 3, 10, 40, 14, 0);
				b_delete_after_create();
				b_create_gdtrahang();
			}
			if (ktVT(685, 70, 980, 110, x, y))
			{
				b_create_menu_title();
				highlight_box(685, 70, 980, 110, (char*)"In hoa don", f_medium, 3, 10, 40, 0, 10);
				b_delete_after_create();
				do_hoa_in_hoadon(error_soHD);
				in_hoa_don_page = true;
			}
			xu_li_tra_cuu_hoa_don(x, y, error_soHD, soHD, in_hoa_don_page, ds_nv);

			if (ktVT(50, 10, 250, 50, x, y) ||
				ktVT(350, 10, 550, 50, x, y) ||
				ktVT(650, 10, 850, 50, x, y) ||
				ktVT(950, 10, 1150, 50, x, y))
			{
				break;
			}

		}
		delay(1);

	}
}



