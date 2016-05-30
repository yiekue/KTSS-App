// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation.NSURLSession;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class NSMutableURLRequest;
@class NSURLSessionTask;
@class NSURLSession;
@class NSURLSessionDataTask;
@class NSData;
@class NSError;
@class NSURLSessionDownloadTask;


/// Absorb all the delegates methods of NSURLSession and forwards them to pretty closures. This is basically the sin eater for NSURLSession.
SWIFT_CLASS("_TtC9SwiftHTTP15DelegateManager")
@interface DelegateManager : NSObject <NSURLSessionDataDelegate, NSURLSessionDelegate, NSURLSessionTaskDelegate>
+ (DelegateManager * _Nonnull)sharedInstance;

/// this is for global authenication handling
@property (nonatomic, copy) NSURLCredential * _Nullable (^ _Nullable auth)(NSURLAuthenticationChallenge * _Nonnull);

/// this is for global request handling
@property (nonatomic, copy) void (^ _Nullable requestHandler)(NSMutableURLRequest * _Nonnull);
- (void)removeTask:(NSURLSessionTask * _Nonnull)task;
- (void)addResponseForTask:(NSURLSessionTask * _Nonnull)task;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLRequest;


/// The class that does the magic. Is a subclass of NSOperation so you can use it with operation queues or just a good ole HTTP request.
SWIFT_CLASS("_TtC9SwiftHTTP4HTTP")
@interface HTTP : NSOperation

/// This is for handling authenication
@property (nonatomic, copy) NSURLCredential * _Nullable (^ _Nullable auth)(NSURLAuthenticationChallenge * _Nonnull);

/// This is for monitoring progress
@property (nonatomic, copy) void (^ _Nullable progress)(float);

/// the actual task
@property (nonatomic, strong) NSURLSessionDataTask * _Null_unspecified task;
+ (NSSet * _Nonnull)keyPathsForValuesAffectingIsReady;
+ (NSSet * _Nonnull)keyPathsForValuesAffectingIsExecuting;
+ (NSSet * _Nonnull)keyPathsForValuesAffectingIsFinished;

/// creates a new HTTP request.
- (nonnull instancetype)init:(NSURLRequest * _Nonnull)req session:(NSURLSession * _Nonnull)session OBJC_DESIGNATED_INITIALIZER;

/// Returns if the task is asynchronous or not. NSURLSessionTask requests are asynchronous.
@property (nonatomic, readonly, getter=isAsynchronous) BOOL asynchronous;
@property (nonatomic, readonly, getter=isReady) BOOL ready;

/// Returns if the task is current running.
@property (nonatomic, readonly, getter=isExecuting) BOOL executing;
@property (nonatomic, readonly, getter=isFinished) BOOL finished;

/// Start the HTTP task. Make sure to set the onFinish closure before calling this to get a response.
- (void)start;

/// Cancel the running task
- (void)cancel;

/// Sets the task to finished. If you aren't using the DelegateManager, you will have to call this in your delegate's URLSession:dataTask:didCompleteWithError: method
- (void)finish;

/// Check not executing or finished when adding dependencies
- (void)addDependency:(NSOperation * _Nonnull)operation;

/// Convenience bool to flag as operation userInitiated if necessary
@property (nonatomic) BOOL userInitiated;

/// Set the global auth handler
+ (void)globalAuth:(NSURLCredential * _Nullable (^ _Nullable)(NSURLAuthenticationChallenge * _Nonnull))handler;

/// Set the global request handler
+ (void)globalRequest:(void (^ _Nullable)(NSMutableURLRequest * _Nonnull))handler;
@end


@interface NSLock (SWIFT_EXTENSION(SwiftHTTP))
@end


@interface NSMutableURLRequest (SWIFT_EXTENSION(SwiftHTTP))

/// Convenience init to allow init with a string. -parameter urlString: The string representation of a URL to init with.
- (nullable instancetype)initWithUrlString:(NSString * _Nonnull)urlString;

/// Used to update the content type in the HTTP header as needed
@property (nonatomic, readonly, copy) NSString * _Nonnull contentTypeKey;

/// Helper method to create the multipart form data
- (NSString * _Nonnull)multiFormHeader:(NSString * _Nonnull)name fileName:(NSString * _Nullable)fileName type:(NSString * _Nullable)type multiCRLF:(NSString * _Nonnull)multiCRLF;

/// Check if the request requires the parameters to be appended to the URL
- (BOOL)isURIParam;
@end

@class NSURL;
@class NSCoder;


/// This is how to upload files in SwiftHTTP. The upload object represents a file to upload by either a data blob or a url (which it reads off disk).
SWIFT_CLASS("_TtC9SwiftHTTP6Upload")
@interface Upload : NSObject <NSCoding>
@property (nonatomic, strong) NSURL * _Nullable fileUrl;
@property (nonatomic, copy) NSString * _Nullable mimeType;
@property (nonatomic, strong) NSData * _Nullable data;
@property (nonatomic, copy) NSString * _Nullable fileName;

/// Tries to determine the mime type from the fileUrl extension.
- (void)getMimeType;

/// Reads the data from disk or from memory. Throws an error if no data or file is found.
- (NSData * _Nullable)getDataAndReturnError:(NSError * _Nullable * _Null_unspecified)error;

/// Standard NSCoder support
- (void)encodeWithCoder:(NSCoder * _Nonnull)aCoder;

/// Required for NSObject support (because of NSCoder, it would be a struct otherwise!)
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder;

/// Initializes a new Upload object with a fileUrl. The fileName and mimeType will be infered.
///
/// -parameter fileUrl: The fileUrl is a standard url path to a file.
- (nonnull instancetype)initWithFileUrl:(NSURL * _Nonnull)fileUrl;

/// Initializes a new Upload object with a data blob.
///
/// -parameter data: The data is a NSData representation of a file's data.
/// -parameter fileName: The fileName is just that. The file's name.
/// -parameter mimeType: The mimeType is just that. The mime type you would like the file to uploaded as.
///
/// upload a file from a a data blob. Must add a filename and mimeType as that can't be infered from the data
- (nonnull instancetype)initWithData:(NSData * _Nonnull)data fileName:(NSString * _Nonnull)fileName mimeType:(NSString * _Nonnull)mimeType;
@end


@interface Upload (SWIFT_EXTENSION(SwiftHTTP))
@end

#pragma clang diagnostic pop
