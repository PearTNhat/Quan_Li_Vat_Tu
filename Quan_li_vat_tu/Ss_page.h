#pragma once

#include "Common.h";

#define MAXTITLE 25
#define I_BG_SS COLOR(186, 245, 223) // màu nền  khi enter nhập xong
#define I_HIGHLIGHT_SS COLOR(255, 255, 255) // highlight khi click vào
#define I_COLOR_SS 0 // màu chữ
#define I_ERROR_COLOR_SS COLOR(255,0,0) // màu của chữ khi báo lỗi


char title[5][MAXTITLE] = { "Top", "Ma VT", "Ten Vat Tu", "Don Vi Tinh", "Doanh Thu" };

// Default value for day/month/year
string day_b = "";
string month_b = "";
string year_b = "";
string day_e = "";
string month_e = "";
string year_e = "";
string year = "";

// DANH SÁCH FUNCTION
bool isLeapYear(int);
bool ktra_loi_input(string, int, string, int, int, int, int, int, int, int);

// kiểm tra năm nhuận
bool isLeapYear(int year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

// Xu li input
bool ktra_loi_input(
	string input,
	int max_value,
	string input_field,
	int input_result,
	int e_kcl, int e_kct,
	int i_error_color, int i_bg, int i_highlight, int i_color
) {
	string error = "";
	
	if (input_field == "day") {
		if (input_result < 1 || input_result > 31) error = "Ngay khong hop le!";
	}
	else if (input_field == "month") {
		if (input_result < 1 || input_result > 12) error = "Thang khong hop le";
	}
	else if (input_field == "year" || input_field == "year_search_doanh_thu") {
		if (input_result < 2003 || input_result > 2023) error = "Nam khong hop le";
	}

	// Thong bao loi
	char m[255];
	strcpy_s(m, error.c_str());
	cout << "Loi input! : " << error << endl;
	int error_padding = 0;
	if (input_field == "year_search_doanh_thu") error_padding += 30;
 	writeText(e_kcl + error_padding, e_kct, m, 2, i_error_color, 8, i_bg);
	// reset lai mau
	setbkcolor(i_highlight);
	setcolor(i_color);
	if (error != "") return 1;
	else return 0;
}

string ss_page_input(
	bool& is_all_valid,
	bool& is_error,
	int& x, int& y,
	int l, int t, int r, int b,
	int kcl, int kct,// can chinh vi tri input
	int e_kcl, int e_kct, int e_length = 50, // can chinh bao loi
	string value = "", int max_value = 255, int type = NULL, string input_field = "year",
	bool isOut = false,
	int i_bg = I_BG,
	int i_highlight = I_HIGHLIGHT,
	int i_color = I_COLOR,
	int i_error_color = I_ERROR_COLOR
) {
	if (!is_all_valid && !is_error) {
		x = y = NULL;
		return "";
	}
	while (kbhit()) {
		getch();
	}
	bool key_enter = false;
	string input = value;
	input += "_";
	char result[255] = { "" };
	if (input.length() != 0) {
		strcpy_s(result, input.c_str());
	}
	text_box(l, t, r, b, (char*)"", f_medium, 1, 0, 0, i_highlight, i_color); // vẽ khung input
	if (is_error) i_color = COLOR(255, 0, 0);
	writeText(l + kcl, t + kct, result, 1, i_color, f_medium, i_highlight); // chữ trong input
	while (!key_enter) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (!ktVT(l, t, r, b, x, y)) {
				out_click:
				//---xoa canh bao
				//setfillstyle(1, i_bg);
				//bar(e_kcl, e_kct, e_kcl+220, e_kct + 20);
				//-- xoa đề render lại từ đầu
				setfillstyle(1, i_highlight);
				bar3d(l, t, r, b, 0, 0);
				//-- ghi chữ lại
				outtextxy(l + kcl, t + kct, result);
				input.erase(input.end() - 1);
				strcpy_s(result, input.c_str());
				cout << "result:" << result << endl;
				// enter  xong vẫn để lại chữ
				setfillstyle(1, 15);
				bar3d(l, t, r, b, 0, 0);
				if (input.length() == 0) {
					is_all_valid = true;
					is_error = false;
				}
				else {
					int input_result = stoi(input);
					is_error = ktra_loi_input(input, max_value, input_field, input_result, e_kcl, e_kct, i_error_color, i_bg, i_highlight, i_color);
					int color = COLOR(0, 0, 0);
					if (is_error) {
						is_all_valid = false;
						color = COLOR(255, 0, 0);
					}
					else is_all_valid = true;
					writeText(l + kcl, t + kct, result, 1, color, f_medium, 15);
				}
				break;
			}
		}
		if (kbhit()) {
			char key = (char)getch(); // nhận key từ bàn phím
			bool check_key;
			cout << "key " << endl;
			if (type == 1) {
				check_key = only_number(key);
			}
			else if (type == 2) {
				check_key = decimal_number(key);
			}
			else if (type == 3) {
				check_key = only_letter(key);
			}
			else {
				check_key = kt_KTu(key);
			}
			if (check_key) {
				if (key == 8) {// <- backspace xoa
					if (input.length() == 1) {

					}
					else {
						setcolor(0); // reset color sau khi input không còn lỗi
						input.erase(input.end() - 2);
					}
				}
				else if (key != 13) {
					if (input.length() == (max_value + 1)) {
						//string s = e_str;
						//char m[255];
						//strcpy_s(m, s.c_str());
						//cout << "Vi tri chu bao loi: " << e_kcl << endl;
						//writeText(e_kcl, e_kct, m, 1, i_error_color, f_medium, i_bg);
						//// reset lai mau
						//setbkcolor(i_highlight);
						//setcolor(i_color);
						continue;
					}
					// them chữ vào input
					input.erase(input.end() - 1);
					input += key;
					input += "_";
				}
				if (input.length() > 2) {
					// kiem tra 2 dau cách, .  thi xoa
					int n = input.length();
					if ((input[n - 2] == input[n - 3]) && (input[n - 2] == ' ' || input[n - 2] == '.')) {
						input.erase(input.end() - 2);
					}
				}
				strcpy_s(result, input.c_str());
				//---xoa canh bao
				setfillstyle(1, i_bg);
				bar(e_kcl-50, e_kct, e_kcl+290, e_kct+20);
				//-- xoa đề render lại từ đầu
				setfillstyle(1, i_highlight);
				bar3d(l, t, r, b, 0, 0);
				//-- ghi chữ lại
				outtextxy(l + kcl, t + kct, result);
				cout << "input: " << input << endl;
				if (key == 13) {
					//enter để break					
					key_enter = true;
					x = NULL; y = NULL;
					input.erase(input.end() - 1);
					strcpy_s(result, input.c_str());
					int input_result;
					if (input != "") input_result = std::stoi(input);
					else input_result = NULL;
					cout << "result:" << input_result << endl;
					// enter xong vẫn để lại chữ
					setfillstyle(1, 15);
					bar3d(l, t, r, b, 0, 0);
					// tiến hành ktra lỗi -------------
					if (input != "") { // Tiến hành kiểm tra lỗi chỉ khi input != ""
						is_error = ktra_loi_input(input, max_value, input_field, (int)input_result, e_kcl, e_kct, i_error_color, i_bg, i_highlight, i_color);
						int color = COLOR(0, 0, 0);
						if (is_error) {
							is_all_valid = false;
							color = COLOR(255, 0, 0); // set color red khi input lỗi
						}
						else is_all_valid = true;
						writeText(l + kcl, t + kct, result, 1, color, f_medium, 15);
					}
				}
			}
			else {
				cout << "ki tu k hop le" << endl;
			}
		}
		if (isOut) goto out_click;
		delay(1);
	}
	cout << "out";
	return input;
}

void create_ss_header() {
	setfillstyle(1, HEADER_BACKGROUND);
	setcolor(0);
	bar3d(10, 65, 1180, 115, 0, 0);
	text_box(15, 70, 310, 110, (char*)"Thong Ke Hoa Don", f_medium, 3, 10, 40, XANH_DUONG_NHAT);
	text_box(320, 70, 640, 110, (char*)"Thong ke doanh thu", f_medium, 3, 10, 40, XANH_DUONG_NHAT);
}

void do_hoa_search_hd() {
	setfillstyle(1, COLOR_INFOR_SG);
	setcolor(0);
	bar3d(280, 180, 920, 530, 0, 0);

	// Thanh tieu de
	const char* title = "Tim Kiem Hoa Don";
	text_box(440, 140, 750, 181, (char*)title, 8, 3, 10, 40, 11, 0); // font 8
	// Thanh tim kiem
	text_box(310, 480, 890, 520, (char*)"Tim kiem", f_medium, 3, 10, 230, COLOR(255, 153, 51), 0);
	// Begin
	text_box(290, 190, 520, 230, (char*)"Tu ngay (begin)", f_medium, 3, 10, 10, 11, 0);
	setfillstyle(1, 15);
	setbkcolor(COLOR_INFOR_SG);
	outtextxy(320, 260, (char*)"Ngay");
	bar3d(400, 250, 500, 285, 0, 0);
	outtextxy(530, 260, (char*)"Thang");
	bar3d(610, 250, 710, 285, 0, 0);
	outtextxy(740, 260, (char*)"Nam");
	bar3d(800, 250, 900, 285, 0, 0);
	// End
	text_box(290, 300, 520, 340, (char*)"Den ngay (end)", f_medium, 3, 10, 10, 11, 0);
	text_box(540, 300, 650, 340, (char*)"TODAY", f_medium, 3, 10, 20, COLOR(252, 186, 3), 0);
	setfillstyle(1, 15);
	setbkcolor(COLOR_INFOR_SG);
	outtextxy(320, 370, (char*)"Ngay");
	bar3d(400, 360, 500, 395, 0, 0);
	outtextxy(530, 370, (char*)"Thang");
	bar3d(610, 360, 710, 395, 0, 0);
	outtextxy(740, 370, (char*)"Nam");
	bar3d(800, 360, 900, 395, 0, 0);
}

void get_current_date(string &day_e, string &month_e, string &year_e) {
	bool is_all_valid = true;
	bool is_error = false;
	int x_daye = 450, y_daye = 251;
	int x_monthe = 611, y_monthe = 361;
	int x_yeare = 801, y_yeare = 361;
	// GET CURRENT TIME ================
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string curr_date = to_string(ltm->tm_mday);
	string curr_month = to_string(1 + ltm->tm_mon);
	string curr_year = to_string(1900 + ltm->tm_year);
	// =================================
	// Xoa báo lỗi
	setfillstyle(1, COLOR_INFOR_SG);
	bar(510 - 50, 445, 510 + 290, 445 + 20); 
	day_e = ss_page_input(is_all_valid, is_error, x_daye, y_daye, 400, 360, 500, 395, 40, 10, 510, 445, 50, curr_date, 2, 1, "day_e", true, COLOR_INFOR_SG);
	month_e = ss_page_input(is_all_valid, is_error, x_monthe, y_monthe, 610, 360, 710, 395, 40, 10, 510, 445, 50, curr_month, 2, 1, "month_e", true, COLOR_INFOR_SG);
	year_e = ss_page_input(is_all_valid, is_error, x_yeare, y_yeare, 800, 360, 900, 395, 30, 10, 510, 445, 50, curr_year, 2, 1, "year_e", true, COLOR_INFOR_SG);
}

bool xu_li_nam_nhuan(int day, int month, int year, string &error_leap_year) {

	if (month == 2) {
		if (isLeapYear(year) && day > 29) {
			//error_leap_year = "Nam " + to_string(year) + " khong co ngay " + to_string(day);
			cout << "year: " << year << endl;
			error_leap_year = "Ngay " + to_string(day) + " khong ton tai";
			return true;
		}
		else if (!isLeapYear(year) && day > 28) {
			//error_leap_year = "Nam " + to_string(year) + " khong co ngay " + to_string(day);
			cout << "year: " << year << endl;
			error_leap_year = "Ngay " + to_string(day) + " khong ton tai";
			return true;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			cout << "truong hop 3" << endl;
			error_leap_year = "Ngay " + to_string(day) + " khong ton tai";
			return true;
		}
	}
	return false;
}

void xu_li_button_tim_kiem(
	bool is_all_valid,
	string dayb, string monthb, string yearb, string daye, string monthe, string yeare
) {
	// check empty
	if (dayb == "" || daye == "" || monthe == "" || monthb == "" || yearb == "" || yeare == "") {
		if (dayb == "") text_box(400, 250, 500, 285, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		if (monthb == "") text_box(610, 250, 710, 285, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		if (yearb == "") text_box(800, 250, 900, 285, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		if (daye == "") text_box(400, 360, 500, 395, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		if (monthe == "") text_box(610, 360, 710, 395, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		if (yeare == "") text_box(800, 360, 900, 395, (char*)"Trong!", f_medium, 2, 8, 20, 15, COLOR(255, 0, 0));
		return;
	}

	// date string to int
	int day_b = stoi(dayb);
	int month_b = stoi(monthb);
	int year_b = stoi(yearb);
	int day_e = stoi(daye);
	int month_e = stoi(monthe);
	int year_e = stoi(yeare);
		
	// Kiểm tra định dạng ngày/tháng/năm
	cout << "day_b = " << day_b << ", month_b = " << month_b << ", year_b =  " << year_b << ", day_e = " << day_e << ", month_e = " << month_e << ", year_e = " << year_e << endl;
	if (!is_all_valid) return; // Ngay/thang/nam không đúng định dạng -> return
	bool error_end = false;	// kiểm tra begin > current
	// get current day
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int curr_date = ltm->tm_mday;
	int curr_month = 1 + ltm->tm_mon;
	int curr_year = 1900 + ltm->tm_year;
	if (curr_year < year_e) {
		error_end = true;
		cout << "year_e = " << year_e << " curr_year = " << curr_year << endl;
	}
	else if (curr_year == year_e) {
		if (month_e > curr_month) {
			error_end = true;
			cout << "month_e = " << month_e << " month_b = " << month_b << endl;
		}
		else if (month_e == curr_month) {
			if (curr_date < day_e) {
				error_end = true;
				cout << "day_e = " << day_e << " curr_date = " << curr_date << endl;
			}
		}
	}

	bool error_begin_end = false;	// kiểm tra begin > end
	if (year_e < year_b) {
		error_begin_end = true;
		cout << "year_e = " << year_e << " < year_b = " << year_b << endl;
	}
	else if (year_e == year_b) {
		if (month_e < month_b) {
			error_begin_end = true;
			cout << "month_e = " << month_e << " < month_b = " << month_b << endl;
		}
		else if (month_e == month_b) {
			if (day_e < day_b) {
				error_begin_end = true;
				cout << "day_e = " << day_e << " < day_b = " << day_b << endl;
			}
		}
	}

	// Kiểm tra năm nhuân
	bool is_error_leap_year_begin;
	bool is_error_leap_year_end;
	string error_leap_year = "";
	is_error_leap_year_begin = xu_li_nam_nhuan(day_b, month_b, year_b, error_leap_year);
	is_error_leap_year_end = xu_li_nam_nhuan(day_e, month_e, year_e, error_leap_year);

	if (is_error_leap_year_begin) {
		char result[255] = { "" };
		strcpy_s(result, to_string(day_b).c_str());
		writeText(400 + 40, 250 + 10, result, 1, COLOR(255, 0, 0), f_medium, 15);
	}
	else { // Trả chữ về màu đen khi không còn lỗi
		char result[255] = { "" };
		strcpy_s(result, to_string(day_b).c_str());
		writeText(400 + 40, 250 + 10, result, 1, 0, f_medium, 15);
	}
	if (is_error_leap_year_end) {
		char result[255] = { "" };
		strcpy_s(result, to_string(day_e).c_str());
		writeText(400 + 40, 360 + 10, result, 1, COLOR(255, 0, 0), f_medium, 15);
	}
	else { // Trả chữ về màu đen khi không còn lỗi
		char result[255] = { "" };
		strcpy_s(result, to_string(day_e).c_str());
		writeText(400 + 40, 360 + 10, result, 1, 0, f_medium, 15);
	}

	// print message
	if (error_leap_year != "") {
		char m[255];
		strcpy_s(m, error_leap_year.c_str());
		writeText(490, 445, m, 2, COLOR(255, 0, 0), 8, COLOR_INFOR_SG);
		return;
	}
	else if (error_end) {
		string error = "Ngay/thang/nam o tuong lai";
		char m[255];
		strcpy_s(m, error.c_str());
		writeText(470, 445, m, 2, COLOR(255, 0, 0), 8, COLOR_INFOR_SG);
	}
	else if (error_begin_end) {
		string error = "Ngay/thang/nam BEGIN > END";
		char m[255];
		strcpy_s(m, error.c_str());
		writeText(470, 445, m, 2, COLOR(255, 0, 0), 8, COLOR_INFOR_SG);
		return;
	} 
}

void do_hoa_search_doanh_thu() {
	setfillstyle(1, COLOR_INFOR_SG);
	setcolor(0);
	bar3d(280, 180, 920, 490, 0, 0);

	// Thanh tieu de
	const char* title = "Tra cuu doanh thu";
	text_box(440, 140, 750, 181, (char*)title, 8, 3, 10, 40, 11, 0); // font 8
	// Thanh tim kiemi
	text_box(450, 410, 750, 450, (char*)"Tra cuu", f_medium, 3, 10, 100, COLOR(255, 153, 51), 0);
	// User input 
	setfillstyle(1, 15);
	setbkcolor(COLOR_INFOR_SG);
	outtextxy(350, 290, (char*)"Nhap nam can tra cuu:");
	bar3d(670, 285, 835, 320, 0, 0);
}


void xu_li_tra_cuu_doanh_thu(int &x, int &y, string &year, bool page) {
	bool is_all_valid = true;
	bool is_error = false;
	if (ktVT(670, 285, 835, 320, x, y) && page) {
		cout << "Tien hanh nhap input --nam";
		year = ss_page_input(is_all_valid, is_error, x, y, 670, 285, 835, 320, 66, 10, 470, 370, 50, year, 4, 1, "year_search_doanh_thu", false, COLOR_INFOR_SG);
	}
}

void  xu_li_thong_ke_hd(
	int &x, int &y, 
	bool &is_all_valid, bool &error_dayb, bool &error_monthb, bool &error_yearb, bool &error_daye, bool &error_monthe, bool &error_yeare,
	string &day_b, string &month_b, string &year_b, 
	string &day_e, string &month_e, string &year_e, 
	bool page
) {
	// Begin ===========================================
	// input day
 	start_input:
	if (ktVT(400, 250, 500, 285, x, y) && page) {
		cout << "Tien hanh nhap input -ngay\n" << endl;
		cout << "is_all_valid: " << is_all_valid << endl;
		cout << "is_error: " << error_dayb << endl;
		day_b = ss_page_input(is_all_valid, error_dayb, x, y, 400, 250, 500, 285, 40, 10, 510, 445, 50, day_b, 2, 1, "day", false, COLOR_INFOR_SG);
		goto start_input;
	}
	// input month
	if (ktVT(610, 250, 710, 285, x, y) && page) {
		cout << "Tien hanh nhap input -thang\n";
		cout << "is_all_valid: " << is_all_valid << endl;
		cout << "is_error: " << error_monthb << endl;
		month_b = ss_page_input(is_all_valid, error_monthb, x, y, 610, 250, 710, 285, 40, 10, 510, 445, 50, month_b, 2, 1, "month", false, COLOR_INFOR_SG);
		goto start_input;
	}
	// input year 
	if (ktVT(800, 250, 900, 285, x, y) && page) {
		cout << "Tien hanh nhap input -nam\n";
		cout << "is_all_valid: " << is_all_valid << endl;
		cout << "is_error: " << error_yearb << endl;
		year_b = ss_page_input(is_all_valid, error_yearb, x, y, 800, 250, 900, 285, 30, 10, 510, 445, 50, year_b, 4, 1, "year", false, COLOR_INFOR_SG);
		goto start_input;
	}

	// Click on TODAY button ====================
	if (ktVT(540, 300, 650, 340, x, y)) {
		text_box(540, 300, 650, 340, (char*)"TODAY", f_medium, 3, 10, 20, COLOR(255, 153, 51), 0);
		get_current_date(day_e, month_e, year_e);
	}

	// End ======================================
	if (ktVT(400, 360, 500, 395, x, y) && page) {
		cout << "Tien hanh nhap input -ngay\n";
		day_e = ss_page_input(is_all_valid, error_daye, x, y, 400, 360, 500, 395, 40, 10, 510, 445, 50, day_e, 2, 1, "day", false, COLOR_INFOR_SG);
		goto start_input;
	}
	if (ktVT(610, 360, 710, 395, x, y) && page) {
		cout << "Tien hanh nhap input -thang\n";
		month_e = ss_page_input(is_all_valid, error_monthe, x, y, 610, 360, 710, 395, 40, 10, 510, 445, 50, month_e, 2, 1, "month", false, COLOR_INFOR_SG);
		goto start_input;
	}

	if (ktVT(800, 360, 900, 395, x, y) && page) {
		cout << "Tien hanh nhap input -nam\n";
		year_e = ss_page_input(is_all_valid, error_yeare, x, y, 800, 360, 900, 395, 30, 10, 510, 445, 50, year_e, 4, 1, "year", false, COLOR_INFOR_SG);
		goto start_input;
	}

	// Click on Tìm kiếm button =================
	if (ktVT(310, 480, 890, 520, x, y) && page) {
		cout << "Click on button tim kiem" << endl;
		xu_li_button_tim_kiem(is_all_valid,day_b, month_b, year_b, day_e, month_e, year_e);
	}
}

