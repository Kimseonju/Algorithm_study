#pragma once

//용도 :
//설명 :
class DefaultClass
{
private: //static
public:  //static func
private: 
public: //member



public: //constructer destructer
	DefaultClass();
	~DefaultClass();

public: 
	DefaultClass(const DefaultClass& _Other) = delete;
	DefaultClass(const DefaultClass&& _Other) = delete;

public:
	DefaultClass& operator=(const DefaultClass& _Other) = delete;
	DefaultClass& operator=(const DefaultClass&& _Other) = delete;

public: //member
};

