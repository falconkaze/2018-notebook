# Spring boot常用配置
## 多文件上传大小设置
Spring boot默认上传文件大小限制为1M。
1. 配置文件
```
spring.http.multipart.max-file-size=64MB
spring.http.multipart.max-request-size=64MB
```
2. 配置bean
```
@Bean  
public MultipartConfigElement multipartConfigElement() {  
    MultipartConfigFactory factory = new MultipartConfigFactory();  
    //单个文件最大  
    factory.setMaxFileSize("10240KB"); //KB,MB  
    // 设置总上传数据总大小  
    factory.setMaxRequestSize("102400KB");  
    return factory.createMultipartConfig();  
}  
```
