/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2017 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.android.animator.AnimatorModule.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "AnimatorModule"

using namespace v8;

namespace ti {
namespace android {
namespace animator {


Persistent<FunctionTemplate> AnimatorModule::proxyTemplate;
jclass AnimatorModule::javaClass = NULL;

AnimatorModule::AnimatorModule() : titanium::Proxy()
{
}

void AnimatorModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Animator"); // use symbol over string for efficiency
	MaybeLocal<Object> maybeInstance = constructor->NewInstance(context);
	Local<Object> moduleInstance;
	if (!maybeInstance.ToLocal(&moduleInstance)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}
	exports->Set(nameSymbol, moduleInstance);
}

void AnimatorModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> AnimatorModule::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "AnimatorModule::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("ti/android/animator/AnimatorModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Animator");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::KrollModule::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<AnimatorModule>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "animate", AnimatorModule::animate);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in AnimatorModule");
		//return;
	}


			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CUBIC_IN_OUT", 6);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUART_IN", 7);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BOUNCE_IN", 28);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUAD_IN", 1);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "ELASTIC_IN", 22);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "SINE_OUT", 14);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUINT_IN", 10);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUART_OUT", 8);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BOUNCE_IN_OUT", 30);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CIRC_OUT", 17);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BACK_IN_OUT", 27);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "EXP_IN", 19);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "SINE_IN_OUT", 15);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "EXP_OUT", 20);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUINT_OUT", 11);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUINT_IN_OUT", 12);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CIRC_IN_OUT", 18);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUAD_IN_OUT", 3);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BACK_IN", 25);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUART_IN_OUT", 9);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "ELASTIC_OUT", 23);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "ELASTIC_IN_OUT", 24);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CUBIC_OUT", 5);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "QUAD_OUT", 2);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BACK_OUT", 26);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "BOUNCE_OUT", 29);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "SINE_IN", 13);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CIRC_IN", 16);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "LINEAR", 0);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "CUBIC_IN", 4);

			DEFINE_INT_CONSTANT(isolate, prototypeTemplate, "EXP_IN_OUT", 21);


	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------
void AnimatorModule::animate(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "animate()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(AnimatorModule::javaClass, "animate", "(Lorg/appcelerator/titanium/proxy/TiViewProxy;Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'animate' with signature '(Lorg/appcelerator/titanium/proxy/TiViewProxy;Lorg/appcelerator/kroll/KrollDict;Lorg/appcelerator/kroll/KrollFunction;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);

	if (args.Length() < 2) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "animate: Invalid number of arguments. Expected 2 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[3];




	if (!args[0]->IsObject() && !args[0]->IsNull()) {
		const char *error = "Invalid value, expected type Object.";
		LOGE(TAG, error);
		titanium::JSException::Error(isolate, error);
		return;
	}
	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Object> arg_0 = args[0]->ToObject(isolate);
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	bool isNew_1;

	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsObjectToJavaKrollDict(
				isolate,
				env, arg_1, &isNew_1);
	} else {
		jArguments[1].l = NULL;
	}

	bool isNew_2;
	if (args.Length() <= 2) {
		jArguments[2].l = NULL;

	} else {

	if (!args[2]->IsNull()) {
		Local<Value> arg_2 = args[2];
		jArguments[2].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_2, &isNew_2);
	} else {
		jArguments[2].l = NULL;
	}
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


			if (isNew_1) {
				env->DeleteLocalRef(jArguments[1].l);
			}


			if (isNew_2) {
				env->DeleteLocalRef(jArguments[2].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}

// Dynamic property accessors -------------------------------------------------


} // animator
} // android
} // ti
