.class public Lfddo/break;
.super Ljava/lang/Object;
.source "SourceFile"


# instance fields
.field private fddo:[I

.field private for:I

.field private ifdf:I


# direct methods
.method public constructor <init>([B)V
    .locals 1

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    const/4 v0, 0x0

    iput v0, p0, Lfddo/break;->ifdf:I

    iput v0, p0, Lfddo/break;->for:I

    invoke-direct {p0, p1}, Lfddo/break;->case([B)[I

    move-result-object p1

    iput-object p1, p0, Lfddo/break;->fddo:[I

    return-void
.end method

.method private case([B)[I
    .locals 5

    const/16 v0, 0x100

    new-array v1, v0, [I

    const/4 v2, 0x0

    move v3, v2

    :goto_0
    if-ge v3, v0, :cond_0

    aput v3, v1, v3

    add-int/lit8 v3, v3, 0x1

    goto :goto_0

    :cond_0
    move v3, v2

    :goto_1
    if-ge v2, v0, :cond_1

    aget v4, v1, v2

    add-int/2addr v3, v4

    array-length v4, p1

    rem-int v4, v2, v4

    aget-byte v4, p1, v4

    add-int/2addr v3, v4

    add-int/2addr v3, v0

    rem-int/2addr v3, v0

    invoke-direct {p0, v2, v3, v1}, Lfddo/break;->else(II[I)V

    add-int/lit8 v2, v2, 0x1

    goto :goto_1

    :cond_1
    return-object v1
.end method

.method private else(II[I)V
    .locals 2

    aget v0, p3, p1

    aget v1, p3, p2

    aput v1, p3, p1

    aput v0, p3, p2

    return-void
.end method

.method public static fddo(Ljava/lang/String;)Ljava/lang/String;
    .locals 2

    new-instance v0, Lfddo/break;

    const-string v1, "b0q1yASlv3LfRmNHA4IZpPvLhuwo"

    invoke-virtual {v1}, Ljava/lang/String;->getBytes()[B

    move-result-object v1

    invoke-direct {v0, v1}, Lfddo/break;-><init>([B)V

    invoke-virtual {v0, p0}, Lfddo/break;->for(Ljava/lang/String;)Ljava/lang/String;

    move-result-object p0

    return-object p0
.end method

.method public static ifdf(Ljava/lang/String;)Ljava/lang/String;
    .locals 0

    return-object p0
.end method


# virtual methods
.method public for(Ljava/lang/String;)Ljava/lang/String;
    .locals 0

    invoke-virtual {p0, p1}, Lfddo/break;->try(Ljava/lang/String;)[B

    move-result-object p1

    invoke-virtual {p0, p1}, Lfddo/break;->new([B)Ljava/lang/String;

    move-result-object p1

    return-object p1
.end method

.method public new([B)Ljava/lang/String;
    .locals 6

    array-length v0, p1

    new-array v0, v0, [B

    const/4 v1, 0x0

    :goto_0
    array-length v2, p1

    if-ge v1, v2, :cond_0

    iget v2, p0, Lfddo/break;->ifdf:I

    add-int/lit8 v2, v2, 0x1

    rem-int/lit16 v2, v2, 0x100

    iput v2, p0, Lfddo/break;->ifdf:I

    iget v3, p0, Lfddo/break;->for:I

    iget-object v4, p0, Lfddo/break;->fddo:[I

    aget v5, v4, v2

    add-int/2addr v3, v5

    rem-int/lit16 v3, v3, 0x100

    iput v3, p0, Lfddo/break;->for:I

    invoke-direct {p0, v2, v3, v4}, Lfddo/break;->else(II[I)V

    iget-object v2, p0, Lfddo/break;->fddo:[I

    iget v3, p0, Lfddo/break;->ifdf:I

    aget v3, v2, v3

    iget v4, p0, Lfddo/break;->for:I

    aget v4, v2, v4

    add-int/2addr v3, v4

    rem-int/lit16 v3, v3, 0x100

    aget v2, v2, v3

    aget-byte v3, p1, v1

    xor-int/2addr v2, v3

    int-to-byte v2, v2

    aput-byte v2, v0, v1

    add-int/lit8 v1, v1, 0x1

    goto :goto_0

    :cond_0
    new-instance p1, Ljava/lang/String;

    invoke-direct {p1, v0}, Ljava/lang/String;-><init>([B)V

    return-object p1
.end method

.method public try(Ljava/lang/String;)[B
    .locals 7

    invoke-virtual {p1}, Ljava/lang/String;->length()I

    move-result v0

    div-int/lit8 v1, v0, 0x2

    new-array v1, v1, [B

    const/4 v2, 0x0

    :goto_0
    if-ge v2, v0, :cond_0

    div-int/lit8 v3, v2, 0x2

    invoke-virtual {p1, v2}, Ljava/lang/String;->charAt(I)C

    move-result v4

    const/16 v5, 0x10

    invoke-static {v4, v5}, Ljava/lang/Character;->digit(CI)I

    move-result v4

    shl-int/lit8 v4, v4, 0x4

    add-int/lit8 v6, v2, 0x1

    invoke-virtual {p1, v6}, Ljava/lang/String;->charAt(I)C

    move-result v6

    invoke-static {v6, v5}, Ljava/lang/Character;->digit(CI)I

    move-result v5

    add-int/2addr v4, v5

    int-to-byte v4, v4

    aput-byte v4, v1, v3

    add-int/lit8 v2, v2, 0x2

    goto :goto_0

    :cond_0
    return-object v1
.end method
