#include <iostream>
#include <cassert>

class Date{

	public:
		using day_type = unsigned short;
		using month_type = unsigned short;
		using year_type = size_t;

	private:
		day_type m_day;
		month_type m_month;
		year_type m_year;
									  // J   F   M   A   M   J   J   A   S   O   N   D
	static constexpr day_type month_len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

	public:
		Date (day_type d = 1, month_type m = 1, year_type y = 1990)
			: m_day(d)
			, m_month(m)
			, m_year(y)
		{
			// Empty
		}

	Date(const Date & clone){
		m_day = clone.m_day;
		m_month = clone.m_month;
		m_year = clone.m_year;
	}

	Date & operator=(const Date & rhs){
		if(this != & rhs){
			m_day = rhs.m_day;
			m_month = rhs.m_month;
			m_year = rhs.m_year;
		}
		return *this;
	}

	/// Sets
	void set_day(day_type new_day){
		m_day = new_day;
	}
	void set_month(month_type new_month){
		m_month = new_month;
	}
	void set_year(year_type new_year){
		m_year = new_year;
	}

	/// Gets
	day_type get_day(void) const{
		return m_day;
	}
	month_type get_month(void) const{
		return m_month;
	}
	year_type get_year(void) const{
		return m_year;
	}

	bool operator>(const Date & rhs){
		auto this_date = m_year*10000 + m_month*100 + m_day;
		auto rhs_date = rhs.m_year*10000 + rhs.m_month*100 + rhs.m_day;
		return this_date > rhs_date;
	}

};

std::ostream & std::cout(std::ostream & os, const Date & d){
	os << d.get_day() << "/" << d.get_month() << "/" << d.get_year();
	return os;
}

int main(){

	Date d(27, 4, 2017);
	std::cout << ">>> Data d = " << d << "\n";

	Date d1;
	std::cout << ">>> Data d1 = " << d1 << "\n";

	Date d2; 
	d2.set_day(24);
	d2.set_month(4);
	d2.set_year(2017);
	std::cout << ">>> Data d1 = " << d1 << "\n";

	d1 = d2;
	std::cout << ">>> Agora temos d1 = " << d1 << "\n";

	Date yesterday(26, 04, 2017);
	Date today(27, 01, 2017);
	Date tomorrow(28, 04, 2017);

	Date d3(30, 2, 2017);
	Date d4(25, 3, 2017);

	Date d5(31, 12, 2016);
	Date d6(1, 1, 2017);

	assert(tomorrow > today);
	assert(tomorrow > yesterday);
	assert(today > yesterday);
	assert(!(yesterday > today));
	assert(!(yesterday > tomorrow));
	assert(!(today > tomorrow));

}