#include "TA.h"

#include <cmath>
#include <utility>

TA::TA()
    : Person(), Student(), Faculty(),
      course_("CS101"), hoursPerWeek_(0.0), responsibilities_("None") {}

TA::TA(std::string name, std::string id, std::string email,
       std::string major, double gpa, int completedCredits,
       std::string department, std::string rank, std::string office,
       std::string course, double hoursPerWeek, std::string responsibilities)
    : Person(name, id, email),
      Student(name, id, email, std::move(major), gpa, completedCredits),
      Faculty(name, id, email, std::move(department), std::move(rank), std::move(office)),
      course_(std::move(course)), hoursPerWeek_(hoursPerWeek), responsibilities_(std::move(responsibilities)) {
    if (course_.empty()) {
        throw std::invalid_argument("course cannot be empty");
    }
    if (!std::isfinite(hoursPerWeek_) || hoursPerWeek_ < 0.0) {
        throw std::invalid_argument("hours per week cannot be negative");
    }
    if (responsibilities_.empty()) {
        throw std::invalid_argument("responsibilities cannot be empty");
    }
}

const std::string& TA::getCourse() const noexcept { return course_; }
void TA::setCourse(const std::string& course) {
    if (course.empty()) {
        throw std::invalid_argument("course cannot be empty");
    }
    course_ = course;
}


double TA::getHoursPerWeek() const noexcept { return hoursPerWeek_; }
void TA::setHoursPerWeek(double hoursPerWeek) {
    if (!std::isfinite(hoursPerWeek) || hoursPerWeek < 0.0) {
        throw std::invalid_argument("hours per week cannot be negative");
    }
    hoursPerWeek_ = hoursPerWeek;
}

const std::string& TA::getResponsibilities() const noexcept { return responsibilities_; }
void TA::setResponsibilities(const std::string& responsibilities) {
    if (responsibilities.empty()) {
        throw std::invalid_argument("responsibilities cannot be empty");
    }
    responsibilities_ = responsibilities;
}

std::string TA::getRole() const {
    return "TA";
}

std::string TA::getDescription() const {
    return "TA for " + course_ + ", helping with " + responsibilities_;
}

double TA::calculateWorkload() const {
    return Student::calculateWorkload() + Faculty::calculateWorkload() + hoursPerWeek_;
}

void TA::display(std::ostream& os) const {
    os << "TA[" << name_ << ", id=" << id_ << ", course=" << course_
       << ", hours=" << hoursPerWeek_ << ", responsibilities=" << responsibilities_ << "]";
}

std::unique_ptr<Person> TA::clone() const {
    return std::make_unique<TA>(*this);
}
