uniform vec2 resolution;
uniform float time;
uniform vec2 mouse;
uniform sampler2D sourceTexture;

void main(){
    const float delay=12.f;
    const float speedupdelay=delay+1.f;
    vec2 uv = gl_FragCoord.xy/resolution.xy;
    float test = uv.y;
    uv.y=1-uv.y;
    float alphaAcc1 = uv.y + .04f*(time-delay)*step(delay,time)* fract(sin(dot(vec2(uv.x), vec2(1.f, 500.f)))* 10.f) + step(speedupdelay,time)*(time-speedupdelay)*(time-speedupdelay)*(time-speedupdelay)*.005f;
    float alphaAcc2 = test + .05f*(time-delay)*step(delay,time)* fract(sin(dot(vec2(uv.x), vec2(1.f, 100.f)))* 100.f) + step(speedupdelay,time)*(time-speedupdelay)*(time-speedupdelay)*(time-speedupdelay)*.001f;

    uv.y+=.002f*time* fract(sin(dot(vec2(uv.x), vec2(1.f, 100.f)))* 10.f);
    
    //uv.x+=.002f*(time-3.f)*(time-3.f)*step(3.f,time)* fract(sin(dot(vec2(uv.y), vec2(1.f, 100.f)))* 1.f);
    vec4 temp=texture(sourceTexture,uv);
    temp.a=1-step(1.f, alphaAcc1-test)-step(1.f, alphaAcc2-uv.y);
    gl_FragColor=temp;
}