#pragma once

#include <base.hpp>

 
class ZeroConstructor: public ByCaseConstructor{
    case_map init() override;
};


class OneConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};


class TwoConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};


class ThreeConstructor: public ByCaseConstructor{
    case_map init() override;
};

class FourConstructor: public ByCaseConstructor{
    case_map init() override;
};


class EightConstructor: public ByCaseConstructor{
    case_map init() override;
};


class FiveToTwentyAndThirtyEndConstructor: public ByCaseConstructor{
    case_map init() override;
};


class FourtyConstructor: public ByCaseConstructor{
    case_map init() override;
};

class HundredConstructor: public ByCaseConstructor{
    case_map init() override;
};

class FiftyToEightyEndConstructor: public ByCaseConstructor{
    case_map init() override;
};

class HundredsEndConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};

class ThousandConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};

class MillionConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};

class BillionConstructor: public ByCaseAndGenderConstructor{
    using ByCaseAndGenderConstructor::ByCaseAndGenderConstructor;
    case_gender_map init() override;
};