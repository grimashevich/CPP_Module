#include "Form.hpp"

Form::Form():
    _name("unknown"),
    _isSigned(false),
    _isExecuted(false),
    _signGrade(150),
    _execGrade(150),
    _target("unknown"),
    GradeTooHighException("Error! To high grade for " + _name),
    GradeTooLowException("Error! To low grade for " + _name)
{

}

Form::Form(std::string name, int signGrade, int execGrade,  std::string target):
    _name(name),
    _isSigned(false),
    _isExecuted(false),
    _signGrade(signGrade),
    _execGrade(execGrade),
    _target(target),
    GradeTooHighException("Error! To high grade for " + _name),
    GradeTooLowException("Error! To low grade for " + _name)
{
    if (signGrade < 1)
        throw GradeTooHighException;
    if (signGrade > 150)
        throw GradeTooHighException;
}

Form::Form(const Form &source):
        _name(source._name),
        _isSigned(source._isSigned),
        _isExecuted(source._isExecuted),
        _signGrade(source._signGrade),
        _execGrade(source._execGrade),
        _target(source._target),
        GradeTooHighException("Error! To high grade for " + _name),
        GradeTooLowException("Error! To low grade for " + _name)
{
    *this = source;
}

Form &Form::operator=(const Form &source)
{
    _isSigned = source._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

std::string Form::getTarget() const
{
    return _target;
}

void Form::BeSigned(Bureaucrat &b)
{
    if (b.getGrade() > getSignGrade())
        throw GradeTooLowException;
    _isSigned = true;
}

Form::~Form()
{

}


std::ostream& operator<<(std::ostream &os, const Form &form)
{
    std::string formSigned = "no";
    if (form.getIsSigned())
        formSigned = "yes";

    return os   << "Form name: " << form.getName() << "; "
                << "signed: " << formSigned << "; "
                << "sign grade: " << form.getSignGrade() << "; "
                << "exec grade: " << form.getExecGrade() << "; ";
}