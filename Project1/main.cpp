#include <iostream>
#include <boost/intrusive_ptr.hpp>
#include <atlbase.h>

void intrusive_ptr_add_ref(IDispatch *pDispatch) { pDispatch->AddRef(); }
void intrusive_ptr_release(IDispatch *pDispatch) { pDispatch->Release(); }

void check_windows_folder()
{
	CLSID clsid;
	CLSIDFromProgID(CComBSTR{ "Scripting.FileSystemObject" }, &clsid);

	void *ptr;
	CoCreateInstance(clsid, 0, CLSCTX_INPROC_SERVER, __uuidof(IDispatch), &ptr);
	boost::intrusive_ptr<IDispatch> disp{ static_cast<IDispatch *>(ptr), false };

	CComDispatchDriver dd{ disp.get() };
	CComVariant arg{ "C:\\Windows" };
	CComVariant ret{ false };

	dd.Invoke1(CComBSTR{ "FolderExists" }, &arg, &ret);
	std::cout << std::boolalpha << (ret.boolVal != 0) << '\n';
}

int main()
{
	CoInitialize(nullptr);
	check_windows_folder();
	CoUninitialize();

	std::cin.get();
	return 0;
}
